#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* largestLexArray(int* A, int N, int B) {
    // Iterate over the array
    for (int i = 0; i < N - 1; i++) {
        // Check if we can perform swaps
        for (int j = i + 1; j < N; j++) {
            // Check if swapping A[i] and A[j] would make the array lexicographically larger
            if (A[i] < A[j]) {
                // If we have remaining swaps, perform the swap
                if (B > 0) {
                    swap(&A[i], &A[j]);
                    B--;
                }
            }
        }
    }
    return A;
}

int main() {
    // Example Input
    int A1[] = {1, 2, 3, 4};
    int B1 = 1;
    int N1 = sizeof(A1) / sizeof(A1[0]);
    int* result1 = largestLexArray(A1, N1, B1);
    printf("Largest lexicographical value array: [");
    for (int i = 0; i < N1; i++) {
        printf("%d ", result1[i]);
    }
    printf("]\n");

    int A2[] = {3, 2, 1};
    int B2 = 2;
    int N2 = sizeof(A2) / sizeof(A2[0]);
    int* result2 = largestLexArray(A2, N2, B2);
    printf("Largest lexicographical value array: [");
    for (int i = 0; i < N2; i++) {
        printf("%d ", result2[i]);
    }
    printf("]\n");

    return 0;
}