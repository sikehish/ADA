#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linear(int arr[], int n, int key)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count++;
        if (arr[i] == key)
            return count;
    }
    return count;
}

void main()
{
    int *arr = NULL;
    int n = 10, key;
    srand(time(NULL));
    int size[] = {10, 100, 1000, 10000, 20000, 40000, 80000};
    FILE *fp = fopen("linear2.dat", "a");

    for (n = 0; n < 7; n++)
    {
        arr = (int *)malloc(sizeof(int) * size[n]);

        // Best
        for (int i = 0; i < size[n]; i++)
            arr[i] = rand();
        fprintf(fp, "%d\t%d\t", size[n], linear(arr, size[n], arr[0]));

        // Avg
        fprintf(fp, "%d\t", linear(arr, size[n], arr[rand() % size[n]]));

        // Worst
        fprintf(fp, "%d\n", linear(arr, size[n], arr[size[n] - 1]));

        free(arr);
    }
    fclose(fp);
}