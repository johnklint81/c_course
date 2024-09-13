#include <stdio.h>

int main(void) {
  // a)
  // Here we declare a variable dbField which is an array. dbField has memory reserved on the stack 
  // the second line tries to change the value of array but this is not allowed, because it is an array not a pointer.

  // double dblField[100];
  // dblField = dblField + 10;
  
  // b)
  // Here we do not try to change the array, instead we change a pointer to the array. This is allowed but may result
  // in the pointer pointing to places outside the reserved memory.
  double dblField[100], *pDblField;
  pDblField = dblField + 10;
}
