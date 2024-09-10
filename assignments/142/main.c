#include <stdio.h>

void dubblera(int x) {
  x = 2 * x;
}

int main(void) {
  int a = 3;
  printf("%d\n", a);
  dubblera(a);
  printf("%d\n", a);
}

/*
 We pass the variable a by value to the function dubblera, not by reference. This means
 that when dubblera doubles the value, it does so in its own scope since it does not
 return the value, a is not updated. 

 To remedy this, we could for example pass a by reference or modify the function to 
 return a value.

 */
