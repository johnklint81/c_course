#include <stdio.h>
#include <string.h>


int main(void) {

  int n = 4;
  double arr1[2][2] = {{0.0, 1.0}, {-1.0, 0.0}};
  double arr2[2][2] = {{0.0, 1.0}, {1.0, 0.0}};
  double arr3[2][2] = {{0.0, -1.0}, {1.0, 0.0}};

  FILE *file1 = fopen("matris1.txt", "w");
  FILE *file2 = fopen("matris2.txt", "w");
  FILE *file3 = fopen("matris3.txt", "w");

  fwrite(arr1, sizeof(double), n, file1);
  fwrite(arr2, sizeof(double), n, file2);
  fwrite(arr3, sizeof(double), n, file3);
 

  // Show and ask why it only prints zero after reading from file without
  // fclose()
  fclose(file1);
  fclose(file2);
  fclose(file3);

  printf("\nPrinting from memory after saving to file:\n");

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%1.1f ", arr1[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%1.1f ", arr2[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%1.1f ", arr3[i][j]);
    }
    printf("\n");
  }

  memset(arr1, 0, sizeof(arr1));
  memset(arr2, 0, sizeof(arr2));
  memset(arr3, 0, sizeof(arr3));

  file1 = fopen("matris1.txt", "r");
  file2 = fopen("matris2.txt", "r");
  file3 = fopen("matris3.txt", "r");

  fread(arr1, sizeof(double), n, file1);
  fread(arr2, sizeof(double), n, file2);
  fread(arr3, sizeof(double), n, file3);

  printf("\nAfter zeroing and reading from file:\n");

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%1.1f ", arr1[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%1.1f ", arr2[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%1.1f ", arr3[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
