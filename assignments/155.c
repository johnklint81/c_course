#include <stdio.h>


// can't pass arr1 or arr2 directly to function as it decays into a pointer, 
// size must be passed separately
void combine(char arr1[], char arr2[], char arr3[],
             size_t size1, size_t size2) {
  // smallest size of the two arrays to be combined
  int matched_size = (size1 < size2) ? size1 : size2;
  int arr3_index = 0;
  // alternate between the lists and fill in at position arr3_index
  for (int i = 0; i < matched_size; ++i) {
    arr3[arr3_index] = arr1[i];
    arr3_index++;
    arr3[arr3_index] = arr2[i];
    arr3_index++;
  }
  // enter the remaining items
  if (size1 > size2) {
    for (int i = matched_size; i < size1; ++i) {
      arr3[matched_size + i] = arr1[i];
    }
  }
  else {
    for (int i = matched_size; i < size2; ++i) {
      arr3[matched_size + i] = arr2[i];
    }
  } 
}

// Something wrong with this function, it appends a null character 
// in the middle of the combined lists for part b)
// Works now, had initialised arr2 as arr2[5], i.e. 2 empty spaces
void combine_sorted(char arr1[], char arr2[], char arr4[], 
                    size_t size1, size_t size2) {
  int arr1_index = 0, arr2_index = 0, arr4_index = 0;
    while (arr1_index < size1 && arr2_index < size2) {
        if (arr1[arr1_index] <= arr2[arr2_index]) {
            arr4[arr4_index] = arr1[arr1_index];
            arr1_index++;
        } 
        else {
            arr4[arr4_index] = arr2[arr2_index];
            arr2_index++;
        }
        arr4_index++;
    }
    // remaining items
    while (arr1_index < size1) {
        arr4[arr4_index] = arr1[arr1_index];
        arr4_index++;
        arr1_index++;
    }

    while (arr2_index < size2) {
        arr4[arr4_index] = arr2[arr2_index];
        arr4_index++;
        arr2_index++;
    }
}


int main(void) {
    char arr1[3] = {'a', 'b', 'c'};   
    char arr2[3] = {'1', '2', '3'};
    size_t size1 = sizeof(arr1) / sizeof(arr1[0]); 
    size_t size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = size1 + size2;
    char arr3[size3];
    char arr4[size3];
    printf("Size of array 1: %lx\n", size1);
    printf("Size of array 2: %lx\n", size2);
    combine(arr1, arr2, arr3, size1, size2);
    printf("The combined array is: \n");
    for (int i = 0; i < size3; ++i) {
      printf("%c ", arr3[i]);
    }
    printf("\n");
    combine_sorted(arr1, arr2, arr4, size1, size2);
    printf("The combined array is: \n");
    for (int i = 0; i < size3; ++i) {
      printf("%c ", arr4[i]);
    }
    printf("\n"); 
}
