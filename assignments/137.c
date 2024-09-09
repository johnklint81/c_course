#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to clear input buffer after invalid input
void clear_input_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

int check_winner(int a, int b) {
  int winner;
  if (a == 0 && b == 1) {
    winner = 0;
  }
  else if (a == 0 && b == 2) {
    winner = 1;
  }
  else if (a == 0 && b == 0) {
    winner = -1;
  }
  else if (a == 1 && b == 2) {
    winner = 0;
  }
  else if (a == 1 && b == 0) {
    winner = 1;
  }
  else if (a == 1 && b == 1) {
    winner = -1;
  }
  else if (a == 2 && b == 0) {
    winner = 0;
  }
  else if (a == 2 && b == 1) {
    winner = 1;
  }
  else if (a == 2 && b == 2) {
    winner = -1;
  }
  return winner;
}
void print_selection(int r) {
  if (r == 0) {
    printf("Datorn valde sten.\n");
  }
  else if (r == 1) {
    printf("Datorn valde sax.\n");
  }
  else {
    printf("Datorn valde påse.\n");
  }
  return;
}

int main(void) {
  srand(time(NULL));
  int selection = -1;
  while (selection != 3) {
    printf("Välj sten (0), sax (1), påse (2) eller (3) för att avsluta: ");
    int res = scanf("%d", &selection);
    fflush(stdin);
    if (selection == 3) {
      printf("Tack för att du spelade!\n");
      return 0;
    }
    if (res != 1 || selection < 0 || selection > 3) {
      clear_input_buffer();
      printf("Felaktig inmatning. Försök igen.\n");
      continue;
    }

  
    int r = rand() / (RAND_MAX / (2 + 1) + 1);  // safe-ish way to generate rands
    print_selection(r);
    int win = check_winner(selection, r);
    switch (win) {
      
      case 0:
        printf("Du vann!\n");
        break;
      case 1:
        printf("Datorn vann!\n");
        break;
      case -1:
        printf("Oavgjort!\n");
        break;
      default:
        break;
    }
  }
}
