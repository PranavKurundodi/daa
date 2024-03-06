#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 10

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to calculate the total cost of an assignment
int calculateCost(int assignment[MAX_SIZE], int costMatrix[MAX_SIZE][MAX_SIZE], int n) {
    int totalCost = 0;
    for (int i = 0; i < n; i++) {
        totalCost += costMatrix[i][assignment[i]];
    }
    return totalCost;
}

// Function to generate all possible assignments using recursion
void generateAssignments(int assignment[MAX_SIZE], int index, int n, int costMatrix[MAX_SIZE][MAX_SIZE], int* minCost) {
    if (index == n) {
        // Calculate the cost for the current assignment
        int currentCost = calculateCost(assignment, costMatrix, n);

        // Update the minimum cost if the current cost is smaller
        *minCost = min(*minCost, currentCost);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (assignment[i] == -1) {
            assignment[i] = index;  // Assign task 'index' to worker 'i'

            // Recursively generate assignments for the remaining tasks
            generateAssignments(assignment, index + 1, n, costMatrix, minCost);

            assignment[i] = -1;  // Backtrack
        }
    }
}

int main() {
    int n;

    printf("Enter the number of workers/tasks (maximum %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid number of workers/tasks. Exiting.\n");
        return 1;
    }

    int costMatrix[MAX_SIZE][MAX_SIZE];

    printf("Enter the cost matrix for the assignment:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    int assignment[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        assignment[i] = -1;  // Initialize assignment array
    }

    int minCost = INT_MAX;

    generateAssignments(assignment, 0, n, costMatrix, &minCost);

    printf("Minimum cost for the optimal assignment: %d\n", minCost);

    return 0;
}
