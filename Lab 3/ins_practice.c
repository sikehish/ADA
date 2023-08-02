#include <stdio.h>
#include <stdlib.h>

int insertionSort(int arr[], int n)
{
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        int flag = 0;
        int ele = arr[i];
        int j = i - 1;
        if (arr[j] < ele)
            count++;
        while (j >= 0 && ele < arr[j])
        {
            count++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = ele;
    }
    return count;
}

void main()
{
    int *arr = NULL;
    int n, count = 0;
    FILE *fp = fopen("ins2.dat", "a");
    int values[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    for (n = 0; n < 10; n++)
    {
        arr = (int *)malloc(sizeof(int) * values[n]);

        // best
        for (int j = 0; j < values[n]; j++)
            arr[j] = j;
        fprintf(fp, "%d\t%d\t", values[n], insertionSort(arr, values[n]));
        // worst
        for (int j = 0; j < values[n]; j++)
            arr[j] = values[n] - j;
        fprintf(fp, "%d\n", insertionSort(arr, values[n]));

        free(arr);
    }
    fclose(fp);
}