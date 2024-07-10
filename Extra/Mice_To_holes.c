#include <stdio.h>
#include <stdlib.h>

// Comparator function for sorting
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minTimeToAssignMice(int* A, int* B, int N) {
    // Sort the arrays A and B
    qsort(A, N, sizeof(int), compare);
    qsort(B, N, sizeof(int), compare);

    // Initialize the minimum time
    int minTime = 0;

    // Calculate the time for each mouse
    for (int i = 0; i < N; i++) {
        int time = abs(A[i] - B[i]);
        if (time > minTime) {
            minTime = time;
        }
    }

    return minTime;
}

int main() {
    // Example Input
    int A1[] = {-4, 2, 3};
    int B1[] = {0, -2, 4};
    int N1 = sizeof(A1) / sizeof(A1[0]);
    printf("Minimum time: %d\n", minTimeToAssignMice(A1, B1, N1));

    int A2[] = {-2};
    int B2[] = {-6};
    int N2 = sizeof(A2) / sizeof(A2[0]);
    printf("Minimum time: %d\n", minTimeToAssignMice(A2, B2, N2));

    return 0;
}