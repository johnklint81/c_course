#include <stdio.h>

int main(void) {
  int num = 5 * 10;
  printf("Låt oss göra lite matte\n");
  // does not work, because I use utf-8 in this terminal, can be verified with echo $LANG
  printf("\x86 \n");
  // here is 'å' in hex in utf-8
  printf("\xc3\xa5\n");
  printf("5 * 10 = %i\n", num);
  /*
  The prepocessor does a number of things: It expands macros and replace them with
  actual values, includes the standard or user defined headers into the file and 
  allows certain parts of the code to be compiled or not based on conditionals.

  The compiler converts the code into machine language, generally binary. It also
  performs error checking and optimisation.

  The linker combines object files and connects external symbols (like functions). 
  It also links library files and handles address binding, i.e. assigns various
  memory addresses to the program.
   */ 
}
