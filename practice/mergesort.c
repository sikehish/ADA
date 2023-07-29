#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

void merge(int *, int *, int *, int, int);

void gen_worst_data(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2, i = 0, j = 0;
        int b[m - l + 1];
        int c[r - m];

        for (i = 0; i <= m - l; i++)
            b[i] = a[2 * i];

        for (i = 0; i < r - m; i++)
            c[i] = a[2 * i + 1];

        gen_worst_data(b, l, m);
        gen_worst_data(c, m + 1, r);

        for (i = 0; i <= m - l; i++)
            a[i] = b[i];

        for (j = 0; j < r - m; j++)
            a[i++] = c[j];
    }
}

void mergeSort(int a[], int n)
{

    if (n < 2)
        return;

    int b[n / 2];
    int c[n / 2];

    int i = 0, j = 0, blen = 0, clen = 0;

    for (i = 0; i < n / 2; i++)
        b[i] = a[i];
    blen = i;

    while (i < n)
    {
        c[j++] = a[i++];
    }
    clen = j;

    mergeSort(b, n / 2);
    mergeSort(c, n / 2);
    merge(a, b, c, blen, clen);
}

void merge(int a[], int b[], int c[], int blen, int clen)
{
    int i = 0, j = 0, k = 0;
    while (i < blen && j < clen)
    {
        if (b[i] > c[j])
        {
            a[k++] = c[j++];
        }
        else
        {
            a[k++] = b[i++];
        }
        count++;
    }
    while (i < blen)
        a[k++] = b[i++];
    while (j < clen)
        a[k++] = c[j++];
}

void main()
{
    int *arr;
    srand(time(NULL));
    FILE *fp;
    fp = fopen("merge.dat", "a");
    int n = 4;
    while (n < 4096)
    {
        arr = (int *)malloc(n * sizeof(int));
        // best case
        count = 0;
        for (int i = 0; i < n; i++)
            arr[i] = i + 1;
        mergeSort(arr, n);
        fprintf(fp, "%d\t%d\t", n, count);

        // avg case
        count = 0;
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % n;
        }
        mergeSort(arr, n);
        fprintf(fp, "%d\t", count);

        // worst case
        count = 0;
        gen_worst_data(arr, 0, n - 1);
        mergeSort(arr, n);
        fprintf(fp, "%d\n", count);

        free(arr);
        n *= 2;
    }
    fclose(fp);
}