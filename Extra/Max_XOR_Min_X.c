#include <stdio.h>

int* maxTwoXOR(int A) {
    static int result[2];
    
    // If A is a power of 2, return [1, A]
    if ((A & (A - 1)) == 0) {
        result[0] = 1;
        result[1] = A;
    } else {
        // Find the highest bit in A
        int highestBit = 0;
        while (A) {
            A >>= 1;
            highestBit++;
        }
        
        // Set X to 1 and Y to the maximum possible value, which is A
        result[0] = 1;
        result[1] = 1 << (highestBit - 1);
    }
    
    return result;
}

int main() {
    // Example Input
    int A1 = 1;
    int* result1 = maxTwoXOR(A1);
    printf("[%d, %d]\n", result1[0], result1[1]);

    int A2 = 2;
    int* result2 = maxTwoXOR(A2);
    printf("[%d, %d]\n", result2[0], result2[1]);

    return 0;
}
