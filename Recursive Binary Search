#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int low, int high, int x, int *count) {
    if (low > high) {
        *count += 1; // element not found
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == x) {
        *count += 2; // element found at mid index
        return mid;
    }
    else if (arr[mid] > x) {
        *count += 3; // compare, then search left subarray
        return binarySearch(arr, low, mid-1, x, count);
    }
    else {
        *count += 3; // compare, then search right subarray
        return binarySearch(arr, mid+1, high, x, count);
    }
}

int main() {
    int n_values[] = {10, 100, 1000, 10000, 100000};
    int num_n_values = sizeof(n_values) / sizeof(int);

    FILE *best_case_file = fopen("binary_search_best_case.txt", "w");
    FILE *worst_case_file = fopen("binary_search_worst_case.txt", "w");

    srand(time(0)); // seed random number generator

    for (int i = 0; i < num_n_values; i++) {
        int n = n_values[i];
        int arr[n];
        for (int j = 0; j < n; j++) {
            arr[j] = j;
        }

        // Best case: element is present at mid index
        int x = arr[n/2];
        int best_case_count = 0;
        binarySearch(arr, 0, n-1, x, &best_case_count);
        fprintf(best_case_file, "%d %d\n",n, best_case_count);

        // Worst case: element is not present in array
        x = -1;
        int worst_case_count = 0;
        binarySearch(arr, 0, n-1, x, &worst_case_count);
        fprintf(worst_case_file, "%d %d\n",n, worst_case_count);
    }

    fclose(best_case_file);
    fclose(worst_case_file);

    return 0;
}
