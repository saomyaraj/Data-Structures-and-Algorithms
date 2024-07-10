#include <stdio.h>

int findMajorityElement(int* A, int N) {
    // Initialize candidate and count
    int candidate = A[0];
    int count = 1;

    // Find candidate for majority element
    for (int i = 1; i < N; i++) {
        if (A[i] == candidate) {
            count++;
        } else {
            count--;
            if (count == 0) {
                candidate = A[i];
                count = 1;
            }
        }
    }

    // Validate candidate
    count = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == candidate) {
            count++;
        }
    }

    // Check if candidate is majority element
    if (count > N / 2) {
        return candidate;
    }

    // Majority element always exists, so no need for error handling
    return -1;
}

int main() {
    // Example Input
    int A[] = {2, 1, 2};
    int N = sizeof(A) / sizeof(A[0]);
    printf("Majority element: %d\n", findMajorityElement(A, N));

    return 0;
}
