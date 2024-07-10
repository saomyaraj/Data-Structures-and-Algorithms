#include <stdio.h>

int minSwitches(int* A, int N) {
    int switches = 0;
    int state = 0; // Current state of the switch

    // Iterate through the array of bulb states
    for (int i = 0; i < N; i++) {
        // If the current bulb is off and the switch is off, toggle the switch and count it as a switch press
        if (A[i] == 0 && state == 0) {
            switches++;
            state = 1; // Switch is now on
        }
        // If the current bulb is on and the switch is on, toggle the switch and count it as a switch press
        else if (A[i] == 1 && state == 1) {
            switches++;
            state = 0; // Switch is now off
        }
    }

    return switches;
}

int main() {
    // Example Input
    int A[] = {0, 1, 0, 1};
    int N = sizeof(A) / sizeof(A[0]);
    printf("Minimum number of switches: %d\n", minSwitches(A, N));

    return 0;
}