#include <stdio.h>

// a)
int main(void) {
  int heltal = 10;
  int *pekare_till_heltal = &heltal;

//  printf("%i\n", pekare_till_heltal + 1);  // tries to print *i with %i, impossible
  printf("%i\n", heltal+1);  // prints 11
  printf("%i\n", *(&heltal)+1); // prints 11, & provides address and * deferences
  printf("%i\n", *(pekare_till_heltal + 1));  // prints the contents of the address + 1
  printf("%i\n", *pekare_till_heltal + 1);  // prints 11, * deferences address
//  printf("%i\n", &heltal + 1);  // tries to print the address + 1 but fails because %i
  
  // b) & returns the address of the variable where scanf stores the input 
}
