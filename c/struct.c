#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  Person person;
  person.name = malloc(strlen("lorran") + 1);
  strcpy(person.name, "lorran");
  printf("name: %s\nage: %d\n", person.name, person.age);
  free(person.name);
  return EXIT_SUCCESS;
}
