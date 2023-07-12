#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count = 0;

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int *arr, int beg, int end)
{

    int i = beg, j = end + 1;
    int pivot = arr[i];

    do
    {
        do
        {
            i++;
            count++;
        } while (i <= end && arr[i] < pivot);

        do
        {
            j--;
            count++;
        } while (j >= beg && arr[j] > pivot);

        if (i < j)
            swap(arr, i, j);

    } while (i < j);

    swap(arr, j, beg);

    return j;
}

void quickSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

void main()
{

    int *arr = NULL;
    srand(time(NULL));
    FILE *fp = fopen("quick.dat", "a");
    int i = 4;
    while (i < 1034)
    {
        arr = (int *)malloc(sizeof(int) * i);
        // best
        count = 0;
        for (int j = 0; j < i; j++)
            arr[j] = 10;
        quickSort(arr, 0, i - 1);
        fprintf(fp, "%d\t%d\t", i, count);

        // avg
        count = 0;
        for (int j = 0; j < i; j++)
            arr[j] = rand() % i;
        quickSort(arr, 0, i - 1);
        fprintf(fp, "%d\t", count);

        // worst
        count = 0;
        for (int j = 0; j < i; j++)
            arr[j] = j;
        quickSort(arr, 0, i - 1);
        fprintf(fp, "%d\n", count);

        free(arr);

        i *= 2;
    }
    fclose(fp);

    system("gnuplot > load 'quick_plot.txt' ");
}