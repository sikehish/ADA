#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int *arr, int low, int high, int key, int *count)
{
    if (low > high)
    {
        return -1;
    }
    int mid = low + (high - low) / 2;
    *count += 1;
    if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid] < key)
    {
        return binarySearch(arr, mid + 1, high, key, count);
    }
    else
    {
        return binarySearch(arr, low, mid - 1, key, count);
    }
}
void main()
{
    srand(time(NULL));
    int count = 0;
    int x, size = 1, key = 0;
    FILE *fptr = fopen("binary.dat", "a");
    while (size < 40000)
    {
        if (size < 1000)
            size *= 10;
        else
            size *= 2;
        fprintf(fptr, "%d\t", size);

        int *arr = (int *)malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++)
            arr[i] = i + 1;
        // best case
        x = binarySearch(arr, 0, size - 1, arr[(size - 1) / 2], &count);
        fprintf(fptr, "%d\t", count);
        count = 0;

        // avg case
        x = binarySearch(arr, 0, size - 1, arr[rand() % size], &count);
        fprintf(fptr, "%d\t", count);
        count = 0;

        // worst case
        x = binarySearch(arr, 0, size - 1, arr[size - 1], &count);
        fprintf(fptr, "%d\n", count);
        count = 0;

        free(arr);
    }

    fclose(fptr);
    system("gnuplot > load 'plotfile2.txt' ");
}

// cd '../../mnt/c/Users/hisha/CodeFiles/ADA lab/Lab 2'