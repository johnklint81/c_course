#include <stdio.h>

int main(void) {
  int n = 4;
  // does not work to initialise arrays with n due to variable-length array size only known at runtime
  // constant size arrays, i.e. 4 are known at compile time
  int int_arr[4] = {1, 2, 3, 4};  // int has size 4 bytes
  char char_arr[4] = {'a', 'b', 'c', 'd'};  // char has size 1 byte
  double dbl_arr[4] = {0.1, 2, 30, 44};  // double has size 8 bytes
 
  // pointers to the arrays
  int *int_ptr = int_arr;
  char *char_ptr = char_arr;
  double *dbl_ptr = dbl_arr;

  // print addresses to int pointers with pointer arithmetic
  printf("int pointers: \n");
  for (int i = 0; i < n; ++i) {
    printf("%p ", (void*)(int_ptr + i));
  }
  printf("\n");
  // verify that the addresses are correct by printing the elements
  for (int i = 0; i < n; ++i) {
    printf("%i ", *(int_ptr + i));
  }
  // print difference in bytes
  printf("\nDifferensen för int arr: %li bytes\n",
         ((void*) &int_ptr[2] - (void*) &int_ptr[1])); 
  printf("\n");
  // print addresses to char pointers
  printf("char pointers: \n");
  for (int i = 0; i < n; ++i) {
    printf("%p ", (void*)(char_ptr + i));
  }
  printf("\n");
  for (int i = 0; i < n; ++i) {
    printf("%c ", *(char_ptr + i));
  }
  // print difference in bytes
  printf("\nDifferensen för char arr: %li bytes\n",
         ((void*) &char_ptr[2] - (void*) &char_ptr[1]));

  printf("\n"); 
  // print addresses to double pointers
  printf("double pointers: \n");
  for (int i = 0; i < n; ++i) {
    printf("%p ", (void*)(dbl_ptr + i));
  }
  // verify correct content at pointer addresses
  printf("\n");
  for (int i = 0; i < n; ++i) {
    printf("%f ", *(dbl_ptr + i));
  }
  printf("\n");
  // print difference in bytes
  printf("Differensen för double arr: %li bytes\n",
         ((void*) &dbl_ptr[2] - (void*) &dbl_ptr[1]));
  printf("\n");
}
