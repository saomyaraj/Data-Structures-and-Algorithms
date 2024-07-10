#include <stdio.h>

int maxProfit(int* A, int n) {
    int maxProfit = 0;
    for (int i = 1; i < n; i++) {
        if (A[i] > A[i - 1]) {
            maxProfit += A[i] - A[i - 1];
        }
    }
    return maxProfit;
}

int main() {
    // Example Input
    int A1[] = {1, 2, 3};
    int n1 = sizeof(A1) / sizeof(A1[0]);
    printf("Max Profit 1: %d\n", maxProfit(A1, n1));

    int A2[] = {5, 2, 10};
    int n2 = sizeof(A2) / sizeof(A2[0]);
    printf("Max Profit 2: %d\n", maxProfit(A2, n2));

    return 0;
}
