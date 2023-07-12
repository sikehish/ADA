#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ct = 0;

void binarySearch(int *arr, int l, int r, int key)
{
    if (l > r)
    {
        ct += l;
        return;
    }
    int m = (l + r) / 2;
    if (arr[m] == key)
    {
        ct += 2;
        return;
    }
    else if (arr[m] < key)
    {
        ct += 3;
        return binarySearch(arr, m + 1, r, key);
    }
    else
    {
        ct += 3;
        return binarySearch(arr, l, m - 1, key);
    }
}

void main()
{
    srand(time(NULL));
    int size = 1, key = 0;
    FILE *fptr = fopen("binary.dat", "a");
    while (size < 40000)
    {
        if (size < 1000)
            size *= 10;
        else
            size *= 2;
        fprintf(fptr, "%d\t", size);

        ct = 0;
        int *arr = (int *)malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++)
            arr[i] = i + 1;
        // best case
        binarySearch(arr, 0, size - 1, arr[(size - 1) / 2]);
        fprintf(fptr, "%d\t", ct);
        ct = 0;

        // avg case
        binarySearch(arr, 0, size - 1, arr[rand() % size]);
        fprintf(fptr, "%d\t", ct);
        ct = 0;

        // worst case
        binarySearch(arr, 0, size - 1, arr[size - 1]);
        fprintf(fptr, "%d\n", ct);
        ct = 0;

        free(arr);
    }

    fclose(fptr);
}