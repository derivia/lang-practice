#include <stdio.h>
#include <stdlib.h>

void fizzBuzz(int n) {
  for (int i = 1; i <= n; i++) {
    if (i % 3 == 0 && i % 5 == 0) {
      printf("fizzbuzz\n");
    } else if (i % 3 == 0) {
      printf("fizz\n");
    } else if (i % 5 == 0) {
      printf("buzz\n");
    } else {
      printf("%d\n", i);
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 1;
  }
  int arg = atoi(argv[1]);
  fizzBuzz(arg);
  return 0;
}
