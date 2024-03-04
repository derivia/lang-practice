#include <stdio.h>
#include <stdlib.h>

/* Pointers are variables that "points" to a memory address.
 * These two operators are used: * and &
 * With * being used to create a pointer to a variable, and as pointer
 * dereferencing, retrieves the value it points and & being used to get the
 * address of a variable in memory.
 *
 * C has two different ways of passing values to functions: passing by value and
 * passing by reference. The first one makes copies of the values into another
 * location in memory, basically doubling the space necessary, and the function
 * isn't able to directly change the value that is in memory, as it doesn't know
 * the value existence.
 *
 * Pointers are also useful and commonly used in data structures like linked lists.
 */

/* Here, three more values are created, and swapByVal can't access the value the
 * variables on the main function are storing it only has access to the copy
 * that is made by making x = num1 and y = num2
 */
void swapByVal(int x, int y) {
  int temp = x;
  x = y;
  y = temp;
}

/* Here, one more value is created (temp) in order to swap the values from num1
 * and num2. The *x and *y are used on the function body in order to get the
 * value that is being pointed by the pointer, not the pointer itself */
void swapByPointer(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int main(int argc, char *argv[]) {
  int num1 = 25;
  int num2 = 50;

  swapByVal(num1, num2);
  printf("Number 1: %d\n", num1);
  printf("Number 2: %d\n", num2);

  swapByPointer(&num1, &num2);
  printf("--- After swapping by pointer ---\n");
  printf("Number 1: %d\n", num1);
  printf("Number 2: %d\n", num2);

  return EXIT_SUCCESS;
}
