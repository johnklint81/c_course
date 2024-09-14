#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *get_size(char **str_arr, int n_words) {
  int *size = malloc(n_words * sizeof(int));
  int i = 0;
  while (str_arr[i] != NULL) {
    size[i] = strlen(str_arr[i]);
    i++;
  }
  return size;
}

void sort1(char **str_arr, int n_words) {
  int i = 0;
  int *size = get_size(str_arr, n_words);
  for (i = 1; i < n_words; ++i) {
    char *temp = str_arr[i];
    int temp_size = size[i];
    int j = i - 1;
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

void sort2(char **str_arr, int n_words) {
    char *temp;
    for (int i = 0; i < n_words - 1; i++) {
        if (str_arr[i] == NULL) continue;
        for (int j = i + 1; j < n_words; j++) {
            if (str_arr[j] == NULL) continue;
            if (strlen(str_arr[i]) == strlen(str_arr[j])) {
                if (strcmp(str_arr[i], str_arr[j]) > 0) {
                    temp = str_arr[i];
                    str_arr[i] = str_arr[j];
                    str_arr[j] = temp;
                }
            }
        }
    }
}

void print_arr(char **str_arr, int n_words) {
    for (int i = 0; i < n_words; i++) {
        if (str_arr[i] != NULL) {
            printf("%s ", str_arr[i]);
        }
    }
    printf("\n");
}

int main(void) {
  int buffer = 1024;
  int n_words = 10;
  char *str = malloc(n_words * buffer * sizeof(char));
  char **str_arr = malloc(n_words * sizeof(char*));
  fgets(str, buffer, stdin);
  // remove newline char
  str[strcspn(str, "\n")] = '\0';
  int i = 0;
  char *word = strtok(str, " "); 
  while (word != NULL) {
    str_arr[i] = strdup(word);
    i++;
    word = strtok(NULL, " ");
  }
  for (int j = i; j < n_words; j++) {
    str_arr[j] = NULL;
  }
  sort1(str_arr, n_words);
  printf("After sorting by length\n");  
  print_arr(str_arr, n_words);
  sort2(str_arr, n_words);
  printf("After alphabetical sorting\n");
  print_arr(str_arr, n_words);
}
