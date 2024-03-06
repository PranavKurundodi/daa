#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CITIES 10

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to calculate the total distance for a given permutation
int calculateDistance(int permutation[], int graph[MAX_CITIES][MAX_CITIES], int n) {
    int distance = 0;

    for (int i = 0; i < n - 1; i++) {
        distance += graph[permutation[i]][permutation[i + 1]];
    }

    // Return to the starting city
    distance += graph[permutation[n - 1]][permutation[0]];

    return distance;
}

// Function to generate all possible permutations using recursion
void generatePermutations(int permutation[], int visited[], int index, int n, int graph[MAX_CITIES][MAX_CITIES], int* minDistance) {
    if (index == n) {
        // Calculate the distance for the current permutation
        int currentDistance = calculateDistance(permutation, graph, n);

        // Update the minimum distance if the current distance is smaller
        *minDistance = min(*minDistance, currentDistance);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            permutation[index] = i;
            visited[i] = 1;

            // Recursively generate permutations for the remaining cities
            generatePermutations(permutation, visited, index + 1, n, graph, minDistance);

            visited[i] = 0;  // Backtrack
        }
    }
}

int main() {
    int n;

    printf("Enter the number of cities (maximum %d): ", MAX_CITIES);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_CITIES) {
        printf("Invalid number of cities. Exiting.\n");
        return 1;
    }

    int graph[MAX_CITIES][MAX_CITIES];

    printf("Enter the distance matrix for the cities:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int permutation[MAX_CITIES];
    int visited[MAX_CITIES] = {0};
    int minDistance = INT_MAX;

    // Start the permutation generation from the first city (0)
    permutation[0] = 0;
    visited[0] = 1;

    generatePermutations(permutation, visited, 1, n, graph, &minDistance);

    printf("Minimum distance for the TSP: %d\n", minDistance);

    return 0;
}
    