#include <stdio.h>
#include <stdlib.h>
int count = 0;

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int beg, int end)
{
    int i = beg;
    int j = end + 1;
    int pivot = arr[beg];

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
            swap(&arr[i], &arr[j]);

    } while (i < j);

    swap(&arr[beg], &arr[j]);

    return j;
}

void quickSort(int arr[], int beg, int end)
{
    if (beg < end)
    {
        int s = partition(arr, beg, end);
        quickSort(arr, beg, s - 1);
        quickSort(arr, s + 1, end);
    }
}

void main()
{
    int n = 4, *arr;
    FILE *fp = fopen("quick2.dat", "a");

    while (n <= 1024)
    {
        arr = (int *)malloc(sizeof(int) * n);

        // Best Case
        count = 0;
        for (int i = 0; i < n; i++)
            arr[i] = n;
        quickSort(arr, 0, n - 1);
        fprintf(fp, "%d\t%d\t", n, count);

        // Average Case
        count = 0;
        for (int i = 0; i < n; i++)
            arr[i] = rand() % n;
        quickSort(arr, 0, n - 1);
        fprintf(fp, "%d\t", count);

        // Worst Case
        count = 0;
        for (int i = 0; i < n; i++)
            arr[i] = i;
        quickSort(arr, 0, n - 1);
        fprintf(fp, "%d\n", count);

        free(arr);
        n *= 2;
    }
    fclose(fp);
}
