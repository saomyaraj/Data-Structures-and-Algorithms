#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent an item in the pool
typedef struct {
    int quality;
    int quantity;
} Item;

// Comparator function for the priority queue
int compare(const void* a, const void* b) {
    return ((Item*)b)->quality - ((Item*)a)->quality; // Max heap based on quality
}

// Function to push an item to the priority queue
void push(Item* pq, int* size, Item item) {
    pq[*size] = item;
    (*size)++;
    qsort(pq, *size, sizeof(Item), compare);
}

// Function to pop the top item from the priority queue
Item pop(Item* pq, int* size) {
    (*size)--;
    return pq[*size];
}

int maxQuantity(int** A, int N) {
    // Initialize variables
    int result = 0;
    Item* pq = (Item*)malloc(N * sizeof(Item));
    int size = 0;

    // Push initial items to the priority queue
    for (int i = 0; i < N; i++) {
        push(pq, &size, (Item){A[i][0], A[i][1]});
    }

    // Greedily pick items until the pool is empty
    while (size > 0) {
        // Pick the item with the highest quality
        Item top = pop(pq, &size);
        result += top.quantity;
        
        // Update the pool by removing items with the same quality
        while (size > 0 && pq[size - 1].quality == top.quality) {
            top.quantity += pq[size - 1].quantity;
            size--;
        }
        
        // Add a new item to the pool with quality floor(X/2) and quantity X*2
        if (top.quality > 0) {
            push(pq, &size, (Item){top.quality / 2, top.quality * 2});
        }
    }

    // Free the memory allocated for the priority queue
    free(pq);

    return result % 1000000007;
}

int main() {
    // Example Input
    int A1[4][2] = {
        {5, 2},
        {2, 11},
        {5, 1},
        {1, 3}
    };
    int N1 = sizeof(A1) / sizeof(A1[0]);
    printf("Maximum quantity: %d\n", maxQuantity(A1, N1));

    int A2[3][2] = {
        {1, 2},
        {1, 1},
        {2, 3}
    };
    int N2 = sizeof(A2) / sizeof(A2[0]);
    printf("Maximum quantity: %d\n", maxQuantity(A2, N2));

    return 0;
}
