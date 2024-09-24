#include <stdio.h>

int main(void) {
  int input;
  int is_number = scanf("%d", &input);

  // Check if input is an integer from return value of scanf
  if (is_number == 1) {
    if (input == 0) {
      printf("Length is 1\n");
      return 1;
    }
    int len = 0;
    input *= 2;
    // while number != zero, increment counter
    while (input) {
      input /= 10;
      len++;
    }
    printf("Length: %d", len);
    return 1;
  }
  // Abort if not exactly one integer was input
  else {
    printf("Incorrect input\n");
    return -1;
  }
}
