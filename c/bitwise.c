#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t decToBinary(uint8_t integer) {
  if (integer == 0) {
    return 0;
  }
  return (integer % 2) + 10 * decToBinary(integer / 2);
}

uint8_t setBitTrue(uint8_t bits, uint8_t position) {
  uint8_t mask = 1 << position;
  return bits | mask;
}

uint8_t setBitFalse(uint8_t bits, uint8_t position) {
  // if position = 2, mask will be = 00000001 << 2, which is 00000100
  // so ~mask will be 11111011, and when AND'ed with bits
  // the position that is 0 in mask will be returned as 0 in result
  uint8_t mask = 1 << position;
  return bits & ~mask;
}

uint8_t flipBit(uint8_t bits, uint8_t position) {
  // if position = 2, mask will be = 00000001 << 2, which is 00000100
  // if bits position 2 is 1, xor will do 1 (bits) 1 (position) = 0 (result)
  // or if bits position 2 is 0, xor will do 0 (bits) 1 (position) = 1 (result)
  uint8_t mask = 1 << position;
  return bits ^ mask;
}

bool isEven(uint8_t bits) {
  // if AND with 00000001 returns 0, it is true, else false
  return ((bits & 1) == 0);
}

bool isPowerOfTwo(uint8_t bits) {
  // if bits is a power of two, bits - 1 will flip all bits "behind" the "power index" to 1
  // which means the AND between those two will be 0 because there was no other bit set as 1
  // other than the one that original bits has, which bits - 1 doesn't have
  return ((bits & bits - 1) == 0);
}

void otherFunctions(uint8_t a);
void primitiveFunctions(uint8_t a, uint8_t b); 

int main(int argc, char *argv[]) {
  uint8_t a = 0b00101010; // 42 in binary
  uint8_t b = 0b01011011; // 91 in binary
  primitiveFunctions(a, b);
  otherFunctions(a);
  return EXIT_SUCCESS;
}

// test (printf) functions

void otherFunctions(uint8_t a) {
  printf("00101010 with position 5 flipped: %08b\n", flipBit(a, 5));
  printf("00101010 with position 4 toggled as true: %08b\n", setBitTrue(a, 4));
  printf("00101010 with position 3 toggled as false: %08b\n", setBitFalse(a, 3));
  printf("00101010 is even: %s\n", isEven(a) ? "true" : "false");
  printf("00101010 is power of two: %s\n", isPowerOfTwo(a) ? "true" : "false");
}

void primitiveFunctions(uint8_t a, uint8_t b) {
  printf("primitive functions between %08b and %08b:\n", a, b);
  printf("AND: %d (%08b)\n", a & b, a & b);
  printf("OR: %d (%08b)\n", a | b, a | b);
  printf("XOR: %d (%08b)\n", a ^ b, a ^ b);
  printf("LEFT SHIFT 2: %d (%08b)\n", a << 2, a << 2);
  printf("RIGHT SHIFT 2: %d (%08b)\n", a >> 2, a >> 2);
}
