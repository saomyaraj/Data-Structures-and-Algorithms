#include <stdio.h>
#include <stdlib.h>

// Struct to represent item
struct Item
{
    int value;
    int weight;
};

// Function to compare items based on their value per unit weight
int compare(const void *a, const void *b) {
    double ratio_a = (double)(((struct Item *)a)->value) / (((struct Item *)a)->weight);
    double ratio_b = (double)(((struct Item *)b)->value) / (((struct Item *)b)->weight);

    if (ratio_a > ratio_b) {
        return -1; //For descending order
    }
    else if (ratio_a < ratio_b) {
        return 1; // For descending order
    }
    else {
        return 0;
    }
}

// Function to solve fractional knapsack problem
double fractionalKnapsack(int W, struct Item items[], int n) {
    // Sort items based on value per unit weight
    qsort(items, n, sizeof(items[0]), compare);

    int curWeight = 0; // Current Weight in knapsack
    double finalValue = 0.0; //Final value of items in knapsack

    // Loop through all the items
    for (int i=0; i<n; i++) {
        // If adding the entire item doesn't exceed the capacity
        if (curWeight + items[i].weight <= W) {
            curWeight += items[i].weight;
            finalValue += items[i].value;
        } else {
            // If adding the entire item exceeds the capacity, add a fraction
            int remain = W - curWeight;
            finalValue += items[i].value * ((double)remain / items[i].weight);
            break;
        }
    }
    return finalValue;
}

int main() {
    int W; //Knapsack capacity
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &W);

    int n; // Number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n]; // Array to store items
    
    //Input items
    printf("Enter the value and weight of each item:\n");
    for (int i=0; i<n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    double maxValue = fractionalKnapsack(W, items, n); // Solving fractional knapsack problem

    printf("Maximum value in the knapsack = %f\n", maxValue);

    return 0;
}