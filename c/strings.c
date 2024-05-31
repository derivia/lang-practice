#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * C isn't an object-oriented language, so it lacks the nowadays common things
 * that most used languages have: classes, objects and methods
 *
 * Strings aren't primitive types in C, so they are created by using an array
 * terminated with \0.
 * The string.h header gives access to useful functions, as
 * examples:
 * strlen() - Gives the length of a string
 * strcpy() - Copies a string
 * strcat() - Concatenates two strings
 */

char *upcaseString(const char *string) {
  char *upcasedString = malloc(strlen(string) + 1);
  // memory allocation handling
  if (upcasedString == NULL) {
    return NULL;
  }
  int i = 0;
  while (string[i]) {
    upcasedString[i] =
        toupper(string[i]); // could use ASCII table and casting, subtracting 32
                            // from the characters between 97 and 122
    i++;
  }
  upcasedString[i] = '\0'; // adds null-termination
  return upcasedString;
}

int main(int argc, char *argv[]) {
  char myName[] = "Lorran";                // creates a string myName
  int myNameStringLength = strlen(myName); // length minus the null character \0
  char *myNameCopied = (char *)malloc(myNameStringLength + 1);
  strcpy(myNameCopied, myName);

  printf("My name: %s\n", myName);
  printf("My name copied: %s\n", myNameCopied);
  printf("My name length: %d\n", myNameStringLength);
  printf("My name in uppercase: %s\n", upcaseString(myName));

  return EXIT_SUCCESS;
}
