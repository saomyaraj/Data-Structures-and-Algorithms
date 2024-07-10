#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("\nSorted array is \n");
    printArray(arr, n);
    return 0;
}


// The insertionSort() function sorts an array arr[] of size n using the Insertion Sort algorithm.
// It iterates through the array starting from the second element (i = 1) to the last element (i = n - 1).
// In each iteration, it selects the element at index i as the key and compares it with the elements to its left.
// If an element to the left of the key is greater than the key, it shifts that element to the right to make space for the key.
// This process continues until the key is correctly positioned in the sorted sub-array to its left.
// The printArray() function is a utility function used to print the elements of the array.
// In the main() function, an example array arr[] is defined, and the insertionSort() function is called to sort the array. The sorted array is then printed.