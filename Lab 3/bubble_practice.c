#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            count++;
            if (arr[j] > arr[j + 1])
            {
                flag = 1;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (flag == 0)
            return count;
    }
    return count;
}

void main()
{
    int *arr = NULL;
    int n, count = 0;
    FILE *fp = fopen("bubble2.dat", "a");
    int values[] = {10, 100, 1000, 2000, 5000, 10000, 20000, 40000};

    for (n = 0; n < 8; n++)
    {
        arr = (int *)malloc(sizeof(int) * values[n]);

        // best
        for (int j = 0; j < values[n]; j++)
            arr[j] = j;
        fprintf(fp, "%d\t%d\t", values[n], bubbleSort(arr, values[n]));
        // worst
        for (int j = 0; j < values[n]; j++)
            arr[j] = values[n] - j;
        fprintf(fp, "%d\n", bubbleSort(arr, values[n]));

        free(arr);
    }
    fclose(fp);
}