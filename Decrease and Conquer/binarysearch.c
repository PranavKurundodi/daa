#include <stdio.h>

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if the key is present at the middle of the array
        if (arr[mid] == key)
            return mid;

        // If the key is smaller, ignore the right half
        else if (arr[mid] > key)
            high = mid - 1;

        // If the key is larger, ignore the left half
        else
            low = mid + 1;
    }

    // If the key is not present in the array
    return -1;
}

int main() {
    int n;

    // Take input for the size of the array
    printf("Enter the size of the sorted array: ");
    scanf("%d", &n);

    int arr[n];

    // Take input for the sorted elements of the array
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int key;

    // Take input for the element to be searched
    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    // Perform binary search
    int result = binarySearch(arr, 0, n - 1, key);

    // Print the result
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in the array\n");

    return 0;
}
