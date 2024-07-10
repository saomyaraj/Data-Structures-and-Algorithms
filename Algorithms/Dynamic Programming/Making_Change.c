#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of coins needed to make up the target amount
int minCoins(int coins[], int n, int amount) {
    // Create an array to store minimum coins required for each amount from 0 to amount
    int dp[amount + 1];
    
    // Initialize the array with a value larger than the maximum amount
    for (int i = 0; i <= amount; i++) {
        dp[i] = INT_MAX;
    }
    
    // Base case: 0 coins are needed to make amount 0
    dp[0] = 0;

    // Loop through each coin denomination
    for (int i = 0; i < n; i++) {
        // Update dp array for each amount from coins[i] to amount
        for (int j = coins[i]; j <= amount; j++) {
            if (dp[j - coins[i]] != INT_MAX && dp[j - coins[i]] + 1 < dp[j]) {
                dp[j] = dp[j - coins[i]] + 1;
            }
        }
    }
    
    // Return the minimum number of coins required for the target amount
    return dp[amount];
}

int main() {
    // Example usage
    int coins[] = {1, 5, 10, 25}; // Available coin denominations
    int n = sizeof(coins) / sizeof(coins[0]); // Number of coin denominations
    int amount = 63; // Target amount

    // Find the minimum number of coins needed
    int min_coins = minCoins(coins, n, amount);
    printf("Minimum number of coins needed for %d cents: %d\n", amount, min_coins);

    return 0;
}


// The function minCoins takes three arguments: an array of coin denominations coins, the number of coin denominations n, and the target amount amount.
// Inside the function, an array dp is initialized to store the minimum number of coins required for each amount from 0 to amount.
// The base case is set where 0 coins are needed to make an amount of 0.
// The function iterates through each coin denomination and updates the dp array for each amount from coins[i] to amount.
// The value in dp[j] is updated to the minimum of its current value and dp[j - coins[i]] + 1.
// Finally, the function returns the minimum number of coins required for the target amount.
// In the main function, an example usage is provided with sample coin denominations and a target amount. The minimum number of coins needed is printed.