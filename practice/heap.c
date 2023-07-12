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

void heapify(int *a, int n, int src)
{
    int largest = src;
    int left = 2 * src;
    int right = 2 * src + 1;

    count++;
    if (left <= n && a[left] > a[largest])
        largest = left;

    if (right <= n && a[right] > a[largest])
        largest = right;

    if (largest != src)
    {
        swap(a, src, largest);
        heapify(a, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2; i >= 1; i--)
        heapify(arr, n, i);
    for (int i = n; i > 1; i--)
    {
        swap(arr, 1, i);
        heapify(arr, i - 1, 1);
    }
}

void main()
{
    int *a, n;
    srand(time(NULL));
    FILE *fp = fopen("heap.dat", "a");

    for (int size = 10; size <= 100; size += 10)
    {
        a = (int *)malloc((size + 1) * sizeof(int));

        // Best Case
        count = 0;
        for (int i = 1; i <= size; i++)
            a[i] = 5;
        heapSort(a, size);
        fprintf(fp, "%d\t%d\t", size, count);

        // Average Case
        count = 0;
        for (int i = 1; i <= size; i++)
            a[i] = rand() % 100;
        heapSort(a, size);
        fprintf(fp, "%d\t", count);

        // Worst Case
        count = 0;
        for (int i = 1; i <= size; i++)
            a[i] = i;
        heapSort(a, size);
        fprintf(fp, "%d\n", count);

        free(a);
    }

    fclose(fp);
}