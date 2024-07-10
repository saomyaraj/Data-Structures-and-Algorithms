#include <stdio.h>
#include <limits.h>

int maxProfit(int* A, int n) {
    int minPrice = INT_MAX;
    int maxProfit = 0;
    
    for (int i = 0; i < n; i++) {
        // Update the minimum price seen so far
        if (A[i] < minPrice) {
            minPrice = A[i];
        }
        // Update the maximum profit if selling on the current day yields more profit
        else if (A[i] - minPrice > maxProfit) {
            maxProfit = A[i] - minPrice;
        }
    }
    return maxProfit;
}

int main() {
    // Example Input
    int A1[] = {1, 2};
    int n1 = sizeof(A1) / sizeof(A1[0]);
    printf("Max Profit 1: %d\n", maxProfit(A1, n1));

    int A2[] = {1, 4, 5, 2, 4};
    int n2 = sizeof(A2) / sizeof(A2[0]);
    printf("Max Profit 2: %d\n", maxProfit(A2, n2));

    return 0;
}
