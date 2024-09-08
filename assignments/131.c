#include <stdio.h>

int main(void) {
  int num;
  printf("Input integer: ");
  int res = scanf("%d", &num);
  if (!res) {
    printf("Invalid input.");
    return 1;
  }
  else {
    int count = 0;
    while (num != 0) {
      count++;
      num >>= 1;
    }
    printf("There are %d bits in that number.\n", count);
  }
}
