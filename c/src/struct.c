#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int main(int argc, char *argv[]) {
  Person person;
  // person.name = "lorran";
  // strings should be dinamically allocated using malloc, strlen and strcpy
  // and freed after
  person.name = malloc(strlen("lorran") + 1);
  strcpy(person.name, "lorran");
  person.age = 19;
  printf("name: %s\nage: %d\n", person.name, person.age);
  free(person.name);
  return EXIT_SUCCESS;
}
