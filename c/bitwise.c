#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void primitiveFunctions(int a, int b) {
  printf("primitive functions between %08b and %08b:\n", a, b);
  printf("AND: %d (%08b)\n", a & b, a & b);
  printf("OR: %d (%08b)\n", a | b, a | b);
  printf("XOR: %d (%08b)\n", a ^ b, a ^ b);
  printf("LEFT SHIFT 2: %d (%08b)\n", a << 2, a << 2);
  printf("RIGHT SHIFT 2: %d (%08b)\n", a >> 2, a >> 2);
}

int flipBit(int bits, int position) {
  // @TODO: flipBit(int bits, int position)
  return bits;
}

bool isEven(int bits) {
  // @TODO: isEven(int bits)
  return bits;
}

bool isPowerOfTwo(int bits) {
  // @TODO: isPowerOfTwo(int bits)
  return bits;
}

int main(int argc, char *argv[]) {
  int a = 0b00101010; // 42 in binary
  int b = 0b01011011; // 91 in binary
  primitiveFunctions(a, b);
  return EXIT_SUCCESS;
}
