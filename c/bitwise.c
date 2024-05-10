#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void primitiveFunctions(uint8_t a, uint8_t b) {
  printf("primitive functions between %08b and %08b:\n", a, b);
  printf("AND: %d (%08b)\n", a & b, a & b);
  printf("OR: %d (%08b)\n", a | b, a | b);
  printf("XOR: %d (%08b)\n", a ^ b, a ^ b);
  printf("LEFT SHIFT 2: %d (%08b)\n", a << 2, a << 2);
  printf("RIGHT SHIFT 2: %d (%08b)\n", a >> 2, a >> 2);
}

uint8_t flipBit(uint8_t bits, uint8_t position) {
  // @TODO: flipBit(uint8_t bits, uint8_t position)
  return bits;
}

bool isEven(uint8_t bits) {
  // @TODO: isEven(uint8_t bits)
  return bits;
}

bool isPowerOfTwo(uint8_t bits) {
  // @TODO: isPowerOfTwo(uint8_t bits)
  return bits;
}

int main(int argc, char *argv[]) {
  uint8_t a = 0b00101010; // 42 in binary
  uint8_t b = 0b01011011; // 91 in binary
  primitiveFunctions(a, b);
  return EXIT_SUCCESS;
}
