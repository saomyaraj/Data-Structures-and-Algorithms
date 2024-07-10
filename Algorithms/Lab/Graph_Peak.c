#include <stdio.h>

// Function to find the peak entry in the unimodal array A
int findPeak(int A[], int n) {
    int low = 0, high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        // Check if mid is the peak
        if (A[mid] > A[mid + 1] && A[mid] > A[mid - 1]) {
            return mid;
        }
        // If A[mid - 1] > A[mid], peak must be in the left half
        else if (A[mid - 1] > A[mid]) {
            high = mid - 1;
        }
        // If A[mid + 1] > A[mid], peak must be in the right half
        else {
            low = mid + 1;
        }
    }

    // Return the index of the peak
    return low;
}

int main() {
    // Example usage
    int A[] = {1, 3, 5, 8, 10, 6, 4, 2}; // Example unimodal array
    int n = sizeof(A) / sizeof(A[0]);

    // Find the peak entry
    int peak = findPeak(A, n);
    printf("Peak entry index: %d\n", peak);

    return 0;
}