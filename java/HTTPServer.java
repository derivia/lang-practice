import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;

class HTTPServer {
  public static void main(String[] args) throws IOException {
    ServerSocket httpServer = new ServerSocket(8080);
    while (true) {
      try (Socket socket = httpServer.accept()) {
        Date currentDateAndTime = new Date();
        String httpResponse = "HTTP/1.1 200 OK\r\n" +
                              "Content-Type: text/plain\r\n" +
                              "Content-Length: " + currentDateAndTime.toString().length() + "\r\n" +
                              "\r\n" +
                              currentDateAndTime;
        socket.getOutputStream().write(httpResponse.getBytes("UTF-8"));
      }
      httpServer.close();
    }
  }
}
