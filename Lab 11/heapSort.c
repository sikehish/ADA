#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count = 0;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    count++;
    if (left <= n && a[left] > a[largest])
        largest = left;

    if (right <= n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        swap(a + i, a + largest);
        heapify(a, n, largest);
    }
}

void heapsort(int a[], int n)
{
    int i;
    // heapification
    for (i = n / 2; i >= 1; i--)
        heapify(a, n, i);
    // replace root witht he bottom last element
    for (i = n; i > 1; i--)
    {
        swap(a + 1, a + i);
        heapify(a, i - 1, 1);
    }
}

int main()
{
    int *a, i, n;
    srand(time(0));
    FILE *fp = fopen("heap.dat", "a");
    for (n = 10; n <= 100; n += 10)
    {
        a = (int *)malloc((n + 1) * sizeof(int));
        // Best case
        count = 0;
        for (i = 1; i <= n; i++)
            a[i] = n;
        heapsort(a, n);
        fprintf(fp, "%d\t%d\t", n, count);

        // Average Case
        for (i = 1; i <= n; i++)
            a[i] = rand() % 100;
        count = 0;
        heapsort(a, n);
        fprintf(fp, "%d\t", count);

        // Worst case
        for (i = 1; i <= n; i++)
            a[i] = i;
        count = 0;
        heapsort(a, n);
        fprintf(fp, "%d\n", count);
        free(a);
    }
    fclose(fp);
    return 0;
}