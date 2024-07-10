#include <stdio.h>

int climbStairs(int A) {
    if (A <= 2) return A;
    
    int dp[A+1];
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= A; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[A];
}

int main() {
    // Example Input
    int A1 = 2;
    printf("Distinct ways to climb %d steps: %d\n", A1, climbStairs(A1));

    int A2 = 3;
    printf("Distinct ways to climb %d steps: %d\n", A2, climbStairs(A2));

    return 0;
}
