#include <stdio.h>
#include "lib1.h"
#include "lib2.h"

// It may not be strictly necessary to include header files for dynamically
// linked objects.

int func1();
int func2();

int main(void) {
  printf("Programstart\n");
  func1();
  func2();
  return 0;
}
