#include <stdio.h>

int main(void) {
  int number = 0;
  int input;
  while (1) {
    printf("Talet är %d, välj en operation: \n", number);
    printf("1) Addera 1\n");
    printf("2) Multiplicera med 2\n");
    printf("3) Subtrahera 3\n");
    printf("4) Avsluta programmet\n");
    int res = scanf("%d", &input);
    if (!res) {
      printf("Incorrect input, terminating.\n");
      return 1;
    }

    switch (input) {
      case 1:
      number += 1;
      break;

      case 2:
      number *= 2;
      break;

      case 3:
      number -= 3;
      break;

      case 4:
      return 0;

      default:
      printf("Incorrect input, terminating.\n");
      return 1;
    } 
  }
}

