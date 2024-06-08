#include <arpa/inet.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/sendfile.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>

// clang-format off
/*
 * @TODO: make this work on the browser (wget works)
 * file descriptors are entries, in format of integers, that represents opened files on the system
 * similarly, socket descriptors are integers that represents open sockets
 * the integer from functions that work with descriptors is something like the descriptor index
 * it's common for functions that create things to return -1 if something went wrong, like memory allocation
 */
// clang-format on

int main(int argc, char *argv[]) {
  // AF_INET expands to 2 & SOCK_STREAM expands to 1
  int socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
  if (socketFileDescriptor == -1) {
    perror("socket creation failed");
    return 1;
  }
  // htons converts the port to network byte order
  // htonl does the same for the IP address, which in this case is INADDR_LOOPBACK (localhost/127.0.0.1 in IPv4)
  // sockaddr_in is a structure that holds an Internet socket address
  struct sockaddr_in addr = {AF_INET, htons(8080), htonl(INADDR_LOOPBACK)};
  // clang-format off
  // binds the socket to the specific address:port combination
  // the return here is only used to check if the bind is succesful
  int socketBind = bind(socketFileDescriptor, (struct sockaddr *)&addr, sizeof(addr));
  // clang-format on
  if (socketBind == -1) {
    perror("bind failed");
    return 1;
  }
  // makes the socket listen on the bound port
  listen(socketFileDescriptor, 32);
  // infinite loop (til program quits) to accept new connections, creating new sockets
  while (1) {
    int clientFileDescriptor = accept(socketFileDescriptor, 0, 0);
    if (clientFileDescriptor == -1) {
      perror("accept failed");
      continue;
    }
    char buffer[1024] = {0};
    // recv is used to receive messages from a socket
    // returns an ssize_t (which is used to represent the message size in bytes)
    // and updates the buffer to the received message content
    ssize_t bytesRead = recv(clientFileDescriptor, buffer, 1024, 0);
    if (bytesRead == -1) {
      perror("recv failed");
      close(clientFileDescriptor);
      continue;
    }
    // gets the first token of buffer, which should have the GET HTTP method
    char *fileName = strtok(buffer, " \t\n");
    if (strcmp(fileName, "GET") != 0) {
      perror("invalid HTTP request");
      close(clientFileDescriptor);
      continue;
    }
    // gets the second token of buffer, which should be the file name
    fileName = strtok(NULL, " \t\n");
    char filePath[1024] = {0};
    // writes the file path to filePath, appending misc/
    snprintf(filePath, sizeof(filePath), "misc/%s", fileName);
    // opens the file in read only mode
    int openedFileDescriptor = open(filePath, O_RDONLY);
    if (openedFileDescriptor == -1) {
      perror("open failed");
      continue;
    }
    off_t offset = 0;
    struct stat fileStat;
    // fstat is used to retrieve information from the file associated with the specified file descriptor and store to an variable
    fstat(openedFileDescriptor, &fileStat);
    // clang-format off
    // sends (copies) the content of the opened file (openedFileDescriptor) to clientFileDescriptor, which is the connection that is waiting on the socket that accepted it
    // the first argument should be an write mode file descriptor
    // and the second should be an read mode file descriptor
    // the last argument is the number in bytes to send in the message, in this case is the size of the file
    ssize_t bytesSent = sendfile(clientFileDescriptor, openedFileDescriptor, &offset, fileStat.st_size);
    // clang-format on
    if (bytesSent == -1) {
      perror("sendfile failed");
      close(openedFileDescriptor);
      close(clientFileDescriptor);
      continue;
    }
    close(openedFileDescriptor);
    close(clientFileDescriptor);
  }
  close(socketFileDescriptor);
  return 0;
}
