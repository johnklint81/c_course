#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// abba,bossob,nitro,kalle,ni talar bra latin,gurka


// counts the number of comma separated sentences in the input string
int count(char *input) {
  int nStrings = 0;
  char *inputPtr = input;
  while (*inputPtr) {
    if (*inputPtr == ',') {      
      nStrings++;
    }
    inputPtr++;
  }
  // number of strings is one more than number of separators
  nStrings++;
  return nStrings;
}

void putInArr(char *input, char **sentences, int nStrings) {
  char *sentence;
  int i = 0;
  // split the input string into substrings based on ',' delimiter
  char *word = strtok(input, ",");
  while (word != NULL) {
    // strdup copies a string, unsure why this is needed but I had bugs without it
    sentences[i] = strdup(word);
    i++;
    // split the remainder of the str string.
    word = strtok(NULL, ",");
  }
}

// Print the array
void printArr(char **sentences, int nStrings) {
    for (int i = 0; i < nStrings; i++) {
        if (sentences[i] != NULL) {
            printf("%s |", sentences[i]);
        }
    }
    printf("\n");
}
// checks for palindrome
int *palindrome(char **sentences, int nStrings) {
  int *palBool = malloc(nStrings * sizeof(int));
  for (int i = 0; i < nStrings; i++) {
    size_t strLength = strlen(sentences[i]);
    // left index
    int j = 0;
    // right index
    int k = strLength - 1;
    // assume palindrome
    int isPalindrome = 1;
    while (j < k) {
      // if a space, skip ahead one step
      if (sentences[i][j] == ' ') {
        j++;
      }
      // ditto, but skip back one step
      if (sentences[i][k] == ' ') {
        k--;
      }
      // if not true, then string is not a palindrome
      if (sentences[i][j] != sentences[i][k]) {
        isPalindrome = 0;          
        break;
      }
      // step
      j++;
      k--;
    }
    palBool[i] = isPalindrome; 
  }
  return palBool;
}

int main(void) {
  size_t size = 1024;
  char *input = malloc(size * sizeof(char));
  int nChars = getline(&input, &size, stdin);
  input[strcspn(input, "\n")] = '\0';
  int nStrings = count(input);
  char **sentences = malloc(nStrings * sizeof(char*));
  putInArr(input, sentences, nStrings);
  int *palBool = palindrome(sentences, nStrings);
  
  // print result, should be in a function but I'm tired...
  printf("Resultat:\n---------------------------------\n");
  for (int i = 0; i < nStrings; i++) {
    printf("%-20s- ", sentences[i]);
    if (palBool[i] == 1) {
      printf("PALINDROM!\n");
    }
    else {
      printf("Inte palindrom\n");
    }
  }
} 
