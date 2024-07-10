#include <stdio.h>
#include <stdlib.h>

// Structure to represent a license
struct License {
    int index;
    double rate;
};

// Compare function for qsort
int compare(const void *a, const void *b) {
    const struct License *l1 = (const struct License *)a;
    const struct License *l2 = (const struct License *)b;
    return (l1->rate > l2->rate) - (l1->rate < l2->rate);
}

// Function to find the order to buy licenses to minimize cost
void findOptimalOrder(double rates[], int n) {
    struct License licenses[n];
    for (int i = 0; i < n; i++) {
        licenses[i].index = i + 1; // License index
        licenses[i].rate = rates[i]; // License growth rate
    }

    // Sort licenses based on growth rates
    qsort(licenses, n, sizeof(struct License), compare);

    // Print the order to buy licenses
    printf("Order to buy licenses to minimize cost:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", licenses[i].index);
    }
    printf("\n");
}

int main() {
    // Example usage
    int n = 5; // Number of licenses
    double rates[] = {1.1, 1.5, 1.3, 1.2, 1.4}; // Growth rates

    // Find the order to buy licenses
    findOptimalOrder(rates, n);

    return 0;
}
