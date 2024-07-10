#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  // Create temporary arrays
  int Left[n1], Right[n2];

  // Copy data to temporary arrays
  for (int i = 0; i < n1; i++) {
    Left[i] = arr[l + i];
  }
  for (int j = 0; j < n2; j++) {
    Right[j] = arr[m + 1 + j];
  }

  // Merge the temporary arrays back into arr[l..r]

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (Left[i] <= Right[j]) {
      arr[k] = Left[i];
      i++;
    } else {
      arr[k] = Right[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of Left[], if there are any
  while (i < n1) {
    arr[k] = Left[i];
    i++;
    k++;
  }

  // Copy the remaining elements of Right[], if there are any
  while (j < n2) {
    arr[k] = Right[j];
    j++;
    k++;
  }
}

// Recursive function to implement Merge Sort
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // Find the middle point
    int m = l + (r - l) / 2;

    // Sort first and second halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted halves
    merge(arr, l, m, r);
  }
}

// Print the array
void printArray(int arr[], int n) {
  printf("Sorted array: \n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {6, 5, 3, 1, 8, 7, 2, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Given array: \n");
  printArray(arr, n);

  mergeSort(arr, 0, n - 1);

  printf("Sorted array: \n");
  printArray(arr, n);

  return 0;
}

// The merge() function merges two sub-arrays of arr[].
// The mergeSort() function divides the array into two halves, sorts the two halves separately, and then merges the sorted halves.
// In the main() function, an example array arr[] is defined, and the mergeSort() function is called to sort the array. The sorted array is then printed.