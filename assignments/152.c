#include <stdio.h>

int main(void) {
  char text[] = "Gothenburg";
  char *my_pointer = text;
  char *copy = *my_pointer;
  int input;
  int len;

  while (1) {
    printf("Strängen är: \"%s\".\n", text);
    printf("Pekaren pekar på \"%c\", välj en operation:\n", *my_pointer);
    printf("1) Plus 1\n");
    printf("2) Minus 1\n");
    printf("4) Avsluta programmet\n");
    int res = scanf("%d", &input);
    if (!res) {
      printf("Fel input, programmet avslutas.\n");
      return 1;
    }
    switch (input) {
      case 1:
        if ((*my_pointer + 1) != '\0' ) {
          my_pointer += 1;
        }
        break;
      case 2:
        if ((*my_pointer - 1) < copy) {
          my_pointer -= 1;   
        }
        break;
      case 4:
        printf("\nProgrammet avslutas.\n");
        return 0;
    }
  }
}
