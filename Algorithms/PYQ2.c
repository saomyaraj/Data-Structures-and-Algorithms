#include <stdio.h>
#include <stdlib.h>

// Structure to store a single transaction
typedef struct {
    int buyDay;
    int sellDay;
    int profit;
} Transaction;

// Comparator function for sorting transactions by profit in descending order
int compare(const void *a, const void *b) {
    Transaction *trans1 = (Transaction *)a;
    Transaction *trans2 = (Transaction *)b;
    return trans2->profit - trans1->profit;
}

// Function to find the maximum profit
int maxProfit(int prices[], int n) {
    int maxTransactions = n / 2;
    Transaction *transactions = malloc(n * n * sizeof(Transaction));
    int transactionCount = 0;

    // Generate all possible profitable transactions
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (prices[j] > prices[i]) {
                transactions[transactionCount++] = (Transaction){i, j, prices[j] - prices[i]};
            }
        }
    }

    // Sort transactions by profit in descending order
    qsort(transactions, transactionCount, sizeof(Transaction), compare);

    // Select up to maxTransactions non-overlapping transactions
    int totalProfit = 0;
    int usedDays[n]; // Array to track days involved in transactions
    for (int i = 0; i < n; i++) usedDays[i] = 0; // Initialize to zero

    int transactionsSelected = 0;
    for (int i = 0; i < transactionCount && transactionsSelected < maxTransactions; i++) {
        if (!usedDays[transactions[i].buyDay] && !usedDays[transactions[i].sellDay]) {
            totalProfit += transactions[i].profit;
            usedDays[transactions[i].buyDay] = 1;
            usedDays[transactions[i].sellDay] = 1;
            transactionsSelected++;
        }
    }

    free(transactions); // Clean up allocated memory
    return totalProfit;
}

// Main function to test the maxProfit function
int main() {
    int prices[] = {10, 15, 7, 20, 5, 25, 30, 12, 18, 22};
    int n = sizeof(prices) / sizeof(prices[0]);
    int result = maxProfit(prices, n);
    printf("Maximum profit is: %d\n", result);
    return 0;
}