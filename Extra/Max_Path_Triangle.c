#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int maximumPathSum(int** A, int N) {
    // Start from the second last row
    for (int i = N - 2; i >= 0; i--) {
        // For each cell in the current row
        for (int j = 0; j <= i; j++) {
            // Calculate the maximum path sum for the current cell
            A[i][j] += max(A[i + 1][j], A[i + 1][j + 1]);
        }
    }
    // The maximum path sum will be in the top cell of the triangle
    return A[0][0];
}

int main() {
    // Example Input
    int N = 4;
    int A1[4][4] = {
        {3, 0, 0, 0},
        {7, 4, 0, 0},
        {2, 4, 6, 0},
        {8, 5, 9, 3}
    };
    // Converting 2D array to 2D pointer array
    int *A1Ptr[4];
    for (int i = 0; i < N; i++) {
        A1Ptr[i] = A1[i];
    }
    printf("Maximum path sum: %d\n", maximumPathSum(A1Ptr, N));

    int A2[4][4] = {
        {8, 0, 0, 0},
        {4, 4, 0, 0},
        {2, 2, 6, 0},
        {1, 1, 1, 1}
    };
    // Converting 2D array to 2D pointer array
    int *A2Ptr[4];
    for (int i = 0; i < N; i++) {
        A2Ptr[i] = A2[i];
    }
    printf("Maximum path sum: %d\n", maximumPathSum(A2Ptr, N));

    return 0;
}
