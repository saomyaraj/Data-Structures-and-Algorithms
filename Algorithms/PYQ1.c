#include <stdio.h>
#include <stdlib.h>

// Structure to represent an asset
struct Asset {
    int cost;
    int quantity;
    int return_rate;
};

// Function to calculate maximum returns after 't' months
int maximizeReturns(struct Asset assets[], int n, int budget, int t) {
    // Creating a 2D array to store maximum returns for each budget and month
    int dp[budget + 1][t + 1];
    
    // Initializing the array with 0s
    for (int i = 0; i <= budget; i++) {
        for (int j = 0; j <= t; j++) {
            dp[i][j] = 0;
        }
    }

    // Populating the array
    for (int i = 1; i <= n; i++) {
        for (int j = assets[i].cost; j <= budget; j++) {
            for (int k = 1; k <= t; k++) {
                if (k >= 1) {
                    int temp = dp[j - assets[i].cost][k - 1] + assets[i].return_rate;
                    dp[j][k] = (temp > dp[j][k]) ? temp : dp[j][k];
                }
            }
        }
    }

    // Returning maximum returns after 't' months
    return dp[budget][t];
}

int main() {
    // Example usage
    int n = 5; // Number of assets
    int budget = 300; // Maximum allocated budget
    int t = 12; // Number of months

    // Initializing asset details
    struct Asset assets[n + 1];
    assets[1].cost = 20;
    assets[1].quantity = 5;
    assets[1].return_rate = 1.5;

    assets[2].cost = 50;
    assets[2].quantity = 2;
    assets[2].return_rate = 1.8;

    assets[3].cost = 10;
    assets[3].quantity = 4;
    assets[3].return_rate = 2.1;

    assets[4].cost = 30;
    assets[4].quantity = 3;
    assets[4].return_rate = 1.1;

    assets[5].cost = 20;
    assets[5].quantity = 2;
    assets[5].return_rate = 0.5;

    // Calculating maximum returns
    int max_returns = maximizeReturns(assets, n, budget, t);
    printf("Maximum returns after %d months: %d\n", t, max_returns);

    return 0;
}
