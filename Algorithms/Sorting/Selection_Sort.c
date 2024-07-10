#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        swap(&arr[min_index], &arr[i]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted array: \n");
    printArray(arr, n);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}



// The selectionSort() function takes an array arr[] and its size n as input and sorts the array using the Selection Sort algorithm.
// In each iteration of the outer loop, it finds the index of the minimum element in the unsorted part of the array (min_index).
// It then swaps the minimum element with the first element of the unsorted part.
// The process is repeated until the entire array is sorted.
// The swap() function is a utility function used to swap two elements.
// The printArray() function is a utility function used to print the elements of the array.
// In the main() function, an example array arr[] is defined, and the selectionSort() function is called to sort the array. The sorted array is then printed.