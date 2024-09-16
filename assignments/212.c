#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  // open file
  FILE *file = fopen("textstring.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }
  // allocate memory
  size_t buf = 100;
  char *content = malloc(buf * sizeof(char));
  // put the content from the file in the memory
  fgets(content, buf, file);
  // print the content from the array it is stored in
  for (int i = 0; i < buf && content[i] != '\0'; i++) {
    if (content[i] == '\n') {
      continue;
    }
    printf("%c", content[i]);
  }
  printf("\n");

  // allocate a size 1 array to (possibly) store the location
  // of the found substring. init it to -1 for no match condition
  int *indices = malloc(sizeof(int));
  indices[0] = -1;
  // pointer to sweep across content, should start at the same
  // memory location as the content pointer 
  char *ptr = content;
  // init array to store the word to search for
  char word[buf];
  printf("Enter the word you are looking for: \n");
  int res = scanf("%s", word);
  int i = 0;
  // strstr returns a pointer to the start of the location the 
  // substring was possibly found at, otherwise returns NULL
  while ((ptr = strstr(ptr, word)) != NULL) {
      // if the while condition is fulfilled then we have found
      // a match. this will have happened ptr - content steps into the string.
      indices[i++] = ptr - content;
      // we must increase the size of the indices array to have available space
      indices = realloc(indices, (i + 1) * sizeof(int));
      // move pointer to end of word
      ptr += strlen(word);
  }
  // print result, could possible shift to 1-indexing here? probably not, weird
  // if match is first substring in sentence
  if (indices[0] != -1) {
    printf("The substring was found ");
    for (int k = 0; k < i; k++) {
      printf("%d, ", indices[k]);
    }
    printf("bytes in. \n");
  }
  else {
    printf("The substring was not found.\n");
  }
}
