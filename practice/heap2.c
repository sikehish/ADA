#include <stdio.h>
#include <stdlib.h>

int count = 0;

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(int *arr, int n, int src)
{
    int largest = src;
    int left = 2 * src;
    int right = 2 * src + 1;

    count++;
    if (left <= n && arr[left] > arr[largest])
        largest = left;
    if (right <= n && arr[right] > arr[largest])
        largest = right;

    if (src != largest)
    {
        swap(&arr[src], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n)
{
    for (int i = n / 2; i >= 1; i--)
        heapify(arr, n, i);
    for (int i = n; i > 1; i--)
    {
        swap(&arr[i], &arr[1]);
        heapify(arr, i - 1, 1);
    }
}

void main()
{
}