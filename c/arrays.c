#include <stdio.h>
#include <stdlib.h>

/*
 * int a[10] creates an array of 10 integers named a
 */

int main(int argc, char *argv[]) {
  int a[10];
  for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++) {
    a[i] = (i + 1) * 3;
    printf("%d\n", a[i]);
  }
  return EXIT_SUCCESS;
}
