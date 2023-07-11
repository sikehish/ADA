#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int beg, int end, int *count)
{
    // int pivot = arr[beg];
    // int i = beg, j = end + 1;
    // do
    // {
    //     do
    //     {
    //         *(count) += 1;
    //         i++;
    //     } while (arr[i] < pivot);
    //     do
    //     {
    //         *(count) += 1;
    //         j--;
    //     } while (arr[j] > pivot);
    //     swap(&arr[i], &arr[j]);
    // } while (i < j);
    // swap(&arr[i], &arr[j]);
    // swap(&arr[beg], &arr[j]);
    // return j;

    int pivot = arr[beg];
    int i = beg + 1, j = end;
    while (i <= j)
    {
        while (arr[i] <= pivot)
        {
            *(count) += 1;
            i++;
        }
        while (arr[j] > pivot)
        {
            *(count) += 1;
            j--;
        }
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    // swap(&arr[i], &arr[j]);
    swap(&arr[beg], &arr[j]);
    // printf("%d: %d\n", j, arr[j]);
    for (int i = beg; i < end + 1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return j;
}

void quicksort(int *arr, int beg, int end, int *count)
{
    if (beg < end)
    {
        int split = partition(arr, beg, end, count);
        quicksort(arr, beg, split - 1, count);
        quicksort(arr, split + 1, end, count);
    }
}

void main()
{

    int arr[] = {4, 1, 2, 0, -1, 11, 9, 21, 25, 4, 7, 1, 3};
    int n = 13;
    int ct = 0;
    quicksort(arr, 0, n - 1, &ct);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}