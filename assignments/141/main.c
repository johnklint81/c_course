#include "convert.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *buffer;
  size_t bufsize = 32;
  float input;
  char *endptr;
  printf("Enter the number to be converted in meters: ");
  if (getline(&buffer, &bufsize, stdin) == -1) {
    printf("Incorrect input.\n");
    return -1;
  }
  input = strtof(buffer, &endptr);

  if (endptr == buffer) {
    printf("Invalid input: No digits found.\n");
  } 
  else if (*endptr != '\n' && *endptr != '\0') {
    printf("Invalid input: Extra characters found.\n");
  }
  else {
  float output = convert(input);
  printf("%.2f meter is %.2f millimeters.\n", input, output);
  }
  free(buffer);
  return 0;
}
