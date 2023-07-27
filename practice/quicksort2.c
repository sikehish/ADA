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

int partition(int arr[], int l, int r)
{
    int start = l;
    int end = r + 1;
    int pivot = arr[l];
    do
    {
        do
        {
            start++;
            count++;
        } while (start <= r && arr[start] < pivot);

        do
        {
            end--;
            count++;
        } while (end >= l && arr[end] > pivot);

        if (start < end)
            swap(arr, start, end);

    } while (start < end);

    swap(arr, end, l);

    return end;
}

void quickSort(int arr[], int l, int r)
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
    FILE *fp = fopen("quick2.dat", "a");
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

    system("gnuplot > load 'quick_plot2.txt' ");
}