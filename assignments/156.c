#include <stdio.h>
#include <stdlib.h>

int main(int argc, int argv[]) {
  
  char c;
  char *new_str;
  int buffer = 1;
  int length = 0;
  // this is the first initialisation of the array, only for one char
  char *str = malloc(sizeof(char));
  
  printf("Enter the string: ");
  // loop and retrieve each char in the input while we have no newline or end of file
  while ((c = getchar()) != '\n' && (c != EOF)) {
    // double the size of buffer if the current string length is the same as the buffer
    if (length == buffer) {
      buffer *= 2;
      // allocate a new temporary string with the contents so far + new space from the doubled buffer size
      new_str = realloc(str, buffer * sizeof(char));
      // assign the temporary string to the original string, now it has additional space for our unknown input size
      str = new_str;
    }
    // increment the length variable and assign the current input char to the string array
    str[length++] = c;
  }
  // Add a terminating null character to the array. 
  str[length] = '\0';

  // split strings into two
  int length1;
  int length2;
  // determine size of arrays
  if (length % 2 == 1) {
    length1 = length / 2 + 1;
    length2 = length / 2;
  }
  else {
    length1 = length / 2;
    length2 = length / 2;
  }

  char *str1 = malloc(sizeof(char) * length1);
  char *str2 = malloc(sizeof(char) * length2);
  int k1 = 0, k2 = 0;
  // assign the values to str1 or str2 depending on index
  for (int i = 0; i < length; ++i) {
    if (i % 2 == 0) {
      str1[k1] = str[i];
      k1++;
    }
    else {
      str2[k2] = str[i];
      k2++;
    }
  }
  // print
  for (int i = 0; i < length1; ++i) {
    printf("%c ", str1[i]);
  }
  printf("\n");
  for (int i = 0; i < length2; ++i) {
    printf("%c ", str2[i]);
  }
  printf("\n");
  free(str);
  free(str1);
  free(str2);
}
