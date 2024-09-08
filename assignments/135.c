#include <stdio.h>
#include <math.h>


int main(void) {
  float pris;
  float betalning;
  printf("Skriv varornas totala pris: ");
  int res1 = scanf("%f", &pris);
  if (!res1) {
    printf("Invalid input.\n");
    return 1;
  }
  if (pris < 0) {
    printf("Priset måste vara positivt.\n");
    return 1;
  }
  printf("Skriv vad du betalar: ");
  int res2 = scanf("%f", &betalning);
  if (!res2) {
    printf("Invalid input.\n");
    return 1;
  }
  if (betalning < pris) {
    printf("Du kan inte betala mindre än det totala priset.\n");
    return 1;
  }
  // Round to closest .50
  float change = round((betalning - pris) * 2) / 2;
  printf("\nDu får %.2f kr tillbaks i växel.\n\n", change);
  int change_counter[9] = {0};
  float denominations[9] = {1000, 500, 100, 50, 20, 10, 5, 1, 0.5};
  for (int i = 0; i < 8; i++) {
      change_counter[i] = (int) change / denominations[i];
        if (change_counter[i] > 0) {
          change -= (float)change_counter[i] * denominations[i];
    }
  }
  if (change >= 0.5) {
    change_counter[9] += 1;
  }
  for (int i = 0; i < 5; ++i) {
    printf("%d st %.0f kr sedlar,\n", change_counter[i], denominations[i]);
  }
  for (int i = 5; i < 8; ++i) {
    printf("%d st %.0f kr mynt,\n", change_counter[i], denominations[i]);
  }
  printf("%d st 50-öringar tillbaks.\n", change_counter[9]);  
}
