/* Comments are like this */
// Or this (After C99)

// Include directives, including standard libraries.
#include <stdio.h>
#include <stdlib.h>

// Defining constants, using the macro definition #define
void printConstant() {
  #define EXAMPLE_CONSTANT 69
  printf("The constant is: %d\n", EXAMPLE_CONSTANT);
}

void printExternalConstant() {
  printf("The constant EXAMPLE_CONSTANT defined on printConstant is accessible: %d\n", EXAMPLE_CONSTANT);
}

/* 
 * Argc and argv are variables that store, respectively, how many arguments were passed and the content of the arguments.
 * Argv is a pointer to an array that stores strings.
 * There should be only one main function: 
 */
int main(int argc, char *argv[]) {
  printConstant();
  printExternalConstant();
  return EXIT_SUCCESS;
}

