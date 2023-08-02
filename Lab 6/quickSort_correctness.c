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
    int n, *arr;
    printf("Enter the size\n");
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n);
    printf("Enter an array\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Entered array\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    quickSort(arr, 0, n - 1);

    printf("Sorted array\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
