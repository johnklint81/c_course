#include <stdio.h>

// This function checks if the input points at NULL and then returns -1 so 
// SafeCopyString can abort. Otherwise it checks if the string is
// null terminated and returns 1.
int nullExceptions(char *dest, const char *origin, size_t count) {
  if (dest == NULL || origin == NULL) {
    printf("Null pointer, aborting.\n");
    return -1;
  }
  for (size_t i = 0; i < count; i++) {
    if (origin[i] == '\0') {
      return 1;
    }
    else {
      return 0;
    }
  }
}


// This function aborts if the string points at NULL. Otherwise it loops 
// through the string and copies from origin to dest and adds '\0' at
// the end. If the string is too long it adds '\0' at the last index.
char *SafeCopyString(char *dest, const char *origin, size_t count) {
  int nullTerminated = nullExceptions(dest, origin, count);
  if (nullTerminated == -1) {
    return NULL;
  }
  size_t i;
  for (i = 0; i < count; i++) {
    if ((nullTerminated == 1) && (origin[i] == '\0')) {
      break;
    }
    dest[i] = origin[i];
  }
  if (i < count) {
    dest[i] = '\0';
  }
  else {
    dest[count - 1] = '\0';
  }
  return dest;
}

int main(void) {
  int buffer = 10;
  char dest[buffer];

  // test cases char[] decays into a pointer when passed to a function
  const char *origin1 = "Bla bla longer than ever"; 
  const char *origin2 = "Shorter";
  const char *origin3 = "\n";
  const char *origin4 = "\0";
  const char origin5[] = {'I', 'm', 'm', 'u', 't', 'a', 'b', 'l', 'e'};
  const char *origin6 = NULL;

  // truncated string
  SafeCopyString(dest, origin1, 10);
  printf("%s\n", dest);

  // full string
  SafeCopyString(dest, origin2, 10);
  printf("%s\n", dest);

  // only prints an additional newline
  SafeCopyString(dest, origin3, 10);
  printf("%s\n", dest);

  // prints nothing as origin4 only contains \0 representing the
  // null character
  SafeCopyString(dest, origin4, 10);
  printf("%s\n", dest);

  // works with immutable strings too
  SafeCopyString(dest, origin5, 10);
  printf("%s\n", dest);

  // Note that it prints Immutable again because it aborts and that
  // is what is left from the previous copy.
  SafeCopyString(dest, origin6, 10);
  printf("%s\n", dest);
}
