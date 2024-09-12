#include <stdio.h>

void dubblera(int *tal) {
  // double the value at the address of the pointer *tal by dereferencing it and
  // multiplying it by 2
  *tal = *tal * 2;
}

int main(void) {
  int tal = 10;
  printf("%p\n", &tal);
  // pass the address of tal to dubblera
  dubblera(&tal);
  printf("%p\n", &tal);
  printf("%d, dubblerad\n", tal);
}
