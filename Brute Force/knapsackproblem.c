#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int calculateValue(int subset[], int val[], int n) {
    int totalValue = 0;
    for (int i = 0; i < n; i++) {
        totalValue += subset[i] * val[i];
    }
    return totalValue;
}

int calculateWeight(int subset[], int wt[], int n) {
    int totalWeight = 0;
    for (int i = 0; i < n; i++) {
        totalWeight += subset[i] * wt[i];
    }
    return totalWeight;
}

void generateSubsets(int subset[], int index, int n, int val[], int wt[], int W, int* maxVal) {
    if (index == n) {
        // Check if the subset is valid (within weight constraint) and has maximum value
        int currentWeight = calculateWeight(subset, wt, n);
        if (currentWeight <= W) {
            int currentValue = calculateValue(subset, val, n);
            *maxVal = max(*maxVal, currentValue);
        }
        return;
    }

    subset[index] = 1;
    generateSubsets(subset, index + 1, n, val, wt, W, maxVal);

    subset[index] = 0;
    generateSubsets(subset, index + 1, n, val, wt, W, maxVal);
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];

    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &val[i], &wt[i]);
    }

    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &W);

    int subset[n];  
    int maxVal = 0;  

    generateSubsets(subset, 0, n, val, wt, W, &maxVal);

    printf("Maximum value that can be obtained: %d\n", maxVal);

    return 0;
}
