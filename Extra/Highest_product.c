#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return a > b ? a : b;
}

// Function to find the minimum of two integers
int min(int a, int b) {
    return a < b ? a : b;
}

long long int highestProduct(int* A, int N) {
    if (N < 3) return -1;

    // Initialize maximum, second maximum, and third maximum
    long long int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    // Initialize minimum and second minimum
    long long int min1 = INT_MAX, min2 = INT_MAX;

    // Find the three maximum and two minimum elements in the array
    for (int i = 0; i < N; i++) {
        if (A[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = A[i];
        } else if (A[i] > max2) {
            max3 = max2;
            max2 = A[i];
        } else if (A[i] > max3) {
            max3 = A[i];
        }

        if (A[i] < min1) {
            min2 = min1;
            min1 = A[i];
        } else if (A[i] < min2) {
            min2 = A[i];
        }
    }

    // Return the maximum of product of top 3 elements or product of top element and bottom two elements
    return max(max1 * max2 * max3, max1 * min1 * min2);
}

int main() {
    // Example Input
    int A1[] = {1, 2, 3, 4};
    int N1 = sizeof(A1) / sizeof(A1[0]);
    printf("Highest product: %lld\n", highestProduct(A1, N1));

    int A2[] = {0, -1, 3, 100, 70, 50};
    int N2 = sizeof(A2) / sizeof(A2[0]);
    printf("Highest product: %lld\n", highestProduct(A2, N2));

    return 0;
}
