#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// @TODO: understand decToBinary better
uint8_t decToBinary(uint8_t integer) {
  if (integer == 0) {
    return 0;
  }
  return (integer % 2) + 10 * decToBinary(integer / 2);
}

void primitiveFunctions(uint8_t a, uint8_t b) {
  printf("primitive functions between %08b and %08b:\n", a, b);
  printf("AND: %d (%08b)\n", a & b, a & b);
  printf("OR: %d (%08b)\n", a | b, a | b);
  printf("XOR: %d (%08b)\n", a ^ b, a ^ b);
  printf("LEFT SHIFT 2: %d (%08b)\n", a << 2, a << 2);
  printf("RIGHT SHIFT 2: %d (%08b)\n", a >> 2, a >> 2);
}

// @TODO: understand flipBit better
uint8_t flipBit(uint8_t bits, uint8_t position) { 
  uint8_t binaryPosition = decToBinary(position);
  uint8_t mask = 1 << binaryPosition;
  return bits ^ mask; 
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
  printf("Byte (00101010) with position 5 flipped: %08b\n", flipBit(a, 5));
  return EXIT_SUCCESS;
}
