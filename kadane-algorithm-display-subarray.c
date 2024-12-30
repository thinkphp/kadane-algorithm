#include <stdio.h>
#include <limits.h> // For INT_MIN

void kadane_with_subarray(int arr[], int n) {
    int max_so_far = INT_MIN; // To store the maximum sum
    int max_ending_here = 0;  // To store the local sum
    int start = 0, end = 0, temp_start = 0;

    for (int i = 0; i < n; i++) {
        if (max_ending_here + arr[i] < arr[i]) {
            max_ending_here = arr[i];
            temp_start = i; // Update temporary start index
        } else {
            max_ending_here += arr[i];
        }

        if (max_ending_here > max_so_far) {
            max_so_far = max_ending_here; // Update global max
            start = temp_start;          // Update start index
            end = i;                     // Update end index
        }
    }

    // Print the results
    printf("Maximum Subarray Sum: %d\n", max_so_far);
    printf("Subarray: ");
    for (int i = start; i <= end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    kadane_with_subarray(arr, n);

    return 0;
}
