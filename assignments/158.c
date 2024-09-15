#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// This function returns the size of the strings in the provided array
int *get_size(char **str_arr, int n_words) {
  int *size = malloc(n_words * sizeof(int));
  int i = 0;
  while (str_arr[i] != NULL) {
    size[i] = strlen(str_arr[i]);
    i++;
  }
  return size;
}

// This function performs the sorting according to lengths of the strings  
void sort1(char **str_arr, int n_words) {
  // Modified version of insertion sort, we consider sublist of one element 
  // sorted, i.e. when i=0.
  int *size = get_size(str_arr, n_words);
  for (int i = 1; i < n_words; ++i) {
    // Select the item to be compared
    char *temp = str_arr[i];
    int temp_size = size[i];
    int j = i - 1;
    // Determine if the size of any of the elements to the left of the current 
    // item i are larger than item j. If so, move to the right side of the 
    // current element.
    while (j >= 0 && str_arr[j] != NULL && size[j] > temp_size) {
      str_arr[j + 1] = str_arr[j];
      size[j + 1] = size[j];
      j--;
    }
    str_arr[j + 1] = temp;
    size[j + 1] = temp_size;
  }
  free(size);
}

// This function performs the alphabetical sorting of strings of the same
// length.
void sort2(char **str_arr, int n_words) {
  char *temp;
  for (int i = 0; i < n_words - 1; i++) {
    // if compare against NULL skip current iteration
    if (str_arr[i] == NULL) continue;
    for (int j = i + 1; j < n_words; j++) {
      // same as above comment
      if (str_arr[j] == NULL) continue;
      // strlen() gives length of a string
      if (strlen(str_arr[i]) == strlen(str_arr[j])) {
        // strcmp() compares two strings and returns 0 if equal, >0 if
        // the first matching char is greater in ASCII than that of str2 and
        // <0 if the first matching char is smaller than that of str2.
        if (strcmp(str_arr[i], str_arr[j]) > 0) {
           temp = str_arr[i];
           str_arr[i] = str_arr[j];
           str_arr[j] = temp;
        }
      }
    }
  }
}

// Print the array
void print_arr(char **str_arr, int n_words) {
    for (int i = 0; i < n_words; i++) {
        if (str_arr[i] != NULL) {
            printf("%s ", str_arr[i]);
        }
    }
    printf("\n");
}

// Main function
// buffer is a limitation of the program
int main(void) {
  int buffer = 1024;
  int n_words = 10;
  char *str = malloc(n_words * buffer * sizeof(char));
  char **str_arr = malloc(n_words * sizeof(char*));
  // get input, fgets() stop reading the buffer after n - 1 characters to prevent buffer overflow
  fgets(str, buffer, stdin);
  // remove newline char
  str[strcspn(str, "\n")] = '\0';
  int i = 0;
  // split the input string into substrings based on space delimiter
  char *word = strtok(str, " ");
  while (word != NULL) {
    // strdup copies a string, unsure why this is needed but I had bugs without
    str_arr[i] = strdup(word);
    i++;
    // split the remainder of the str string.
    word = strtok(NULL, " ");
  }
  sort1(str_arr, n_words);
  printf("After sorting by length\n");  
  print_arr(str_arr, n_words);
  sort2(str_arr, n_words);
  printf("After alphabetical sorting\n");
  print_arr(str_arr, n_words);
  free(str);
  free(str_arr);
}
