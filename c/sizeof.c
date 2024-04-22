#include <stdio.h>
#include <stdlib.h>

// Character literal has a size of integer, instead of char
int main(int argc, char *argv[]) {
  printf("sizeof(int) %zu\n", sizeof(int));
  printf("sizeof(char) %zu\n", sizeof(char));
  printf("sizeof('a') %zu\n", sizeof('a'));
  return EXIT_SUCCESS;
}
