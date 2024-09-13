#include <stdio.h>


// can't pass arr1 or arr2 directly to function as it decays into a pointer, size must be passed separately
void combine(int arr1[], int arr2[], int arr3[], size_t size1, size_t size2) {
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

void combine_sorted(int arr1[], int arr2[], int arr4[], size_t size1, size_t size2) {
  int arr1_index = 0, arr2_index = 0, arr4_index = 0;
    while (arr1_index < size1 && arr2_index < size2) {
        if (arr1[arr1_index] <= arr2[arr2_index]) {
            arr4[arr4_index] = arr1[arr1_index];
            arr1_index++;
        } else {
            arr4[arr4_index] = arr2[arr2_index];
            arr2_index++;
        }
        arr4_index++;
    }

    // Copy remaining elements from arr1 (if any)
    while (arr1_index < size1) {
        arr4[arr4_index] = arr1[arr1_index];
        arr4_index++;
        arr1_index++;
    }

    // Copy remaining elements from arr2 (if any)
    while (arr2_index < size2) {
        arr4[arr4_index] = arr2[arr2_index];
        arr4_index++;
        arr2_index++;
    }
}

int main(void) {
    int arr1[3] = {1, 2, 12};
    int arr2[5] = {5, 6, 7, 8, 9};
    size_t size1 = sizeof(arr1) / sizeof(arr1[0]); 
    size_t size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = size1 + size2;
    int arr3[size3];
    int arr4[size3];
    printf("Size of array 1: %lx\n", size1);
    printf("Size of array 2: %lx\n", size2);
    combine(arr1, arr2, arr3, size1, size2);
    printf("The combined array is: \n");
    for (int i = 0; i < size3; ++i) {
      printf("%d ", arr3[i]);
    }
    printf("\n");
    combine_sorted(arr1, arr2, arr4, size1, size2);
    printf("The combined array is: \n");
    for (int i = 0; i < size3; ++i) {
      printf("%d ", arr4[i]);
    }
    printf("\n"); 
}
