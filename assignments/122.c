#include <stdio.h>

int main(void) {
  fflush(stdin);
  int P, Q;
  printf("Enter an integer P: ");
  // Scan input stream and save result at the address P points to
  int result1 = scanf("%d", &P);
  // Guard for incorrect input
  if (!result1) {
    printf("Incorrect input.\n");
    return -1;
  }
  printf("Enter an integer Q: ");
  int result2 = scanf("%d", &Q);
  if (!result2) {
    printf("Incorrect input.\n");
    return -1;
  }
  printf("P in hex: %x\n", P);
  printf("P / Q = %.3f\n", (float)P / (float)Q);  // May be enough to only cast P
  printf("P %% Q = %d\n", P % Q);  // Note modulo 0 is undefined behavior in C
  printf("Q * P = %.4e\n", (float)Q * (float)P);
  printf("Q with zero padding: %09d\n", Q);
  return 0;
}
