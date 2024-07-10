#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int longestCommonSubsequence(char* A, char* B) {
    int m = strlen(A);
    int n = strlen(B);

    int dp[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    // Example Input
    char A[] = "abbcdgf";
    char B[] = "bbadcgf";
    printf("Length of longest common subsequence: %d\n", longestCommonSubsequence(A, B));

    return 0;
}
