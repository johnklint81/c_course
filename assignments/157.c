#include <stdio.h>
#include <stdlib.h>


int main(void) {
  printf("Hur många ord vill du mata in? ");
  int n_words;
  int res = scanf("%d", &n_words);
  // flush input buffer which contains \n
  getchar();
  printf("Ge %d ord nu:\n", n_words);
  int i = 0;
  char **str_arr = malloc(n_words * sizeof(char*)); 
  while (i < n_words) {
    int length = 0;
    int buffer = 1;
    char c;
    char *new_str;
    char *str = malloc(sizeof(char));
    while ((c = getchar()) != '\n' && (c != EOF) && (i < n_words)) {
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
    // Add a terminating null character to the array.
    str[length] = '\0';
    str_arr[i] = str;
    }
    i++;
  }
  printf("Här är dina ord: \n");
  for (int i = 0; i < n_words; ++i) {
    printf("%c\n", *str_arr[i]);
    free(str_arr[i]);
  }
  free(str_arr);
}
