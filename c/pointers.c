#include <stdlib.h>
#include <stdio.h>

/* Pointers are variables that "points" to a memory address.
 * These two operators are used: * and &
 * With * being used to create a pointer to a variable, and as pointer dereferencing, retrieves the value it points
 * and & being used to get the address of a variable in memory.
 */

int retrievePointerValue() {
  int number = 24; // the value that number holds won't change the location it is located, since it would use the same amount of bits
  printf("%p", &number); // prints the memory address of the variable number
  int *pointerToNumber = &number; // creates a pointer to the address of number in memory;
  return *pointerToNumber; // returns the value pointed by pointerToNumber, in this case: 24;
}

int main(int argc, char *argv[]) {
  printf("%d", retrievePointerValue());
  return EXIT_SUCCESS;
}
