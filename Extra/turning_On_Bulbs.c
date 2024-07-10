#include <stdio.h>

int minStepsToTurnOnBulbs(int A) {
    // Calculate the minimum number of steps required
    // Divide the number of bulbs by 3 and round up
    int steps = (A + 2) / 3;
    return steps;
}

int main() {
    // Example Input
    int A1 = 3;
    printf("Minimum number of steps: %d\n", minStepsToTurnOnBulbs(A1));

    int A2 = 1;
    printf("Minimum number of steps: %d\n", minStepsToTurnOnBulbs(A2));

    return 0;
}