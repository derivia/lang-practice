#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // 42 in binary
  int a = 0b00101010;
  // 91 in binary
  int b = 0b01011011;
  // AND
  printf("%d\n", a & b);
  // OR
  printf("%d\n", a | b);
  // XOR (exclusive OR)
  printf("%d\n", a ^ b);
  // LEFT SHIFT: 0b10101000
  printf("%d\n", a << 2);
  // RIGHT SHIFT: 0b00001010
  printf("%d\n", a >> 2);
  // NOT
  printf("%d\n", ~a);
  return EXIT_SUCCESS;
}
