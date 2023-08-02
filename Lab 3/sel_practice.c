#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int selSort(int arr[], int n)
{
    int count = 0, i;
    for (i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            count++;
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    return count;
}

void main()
{
    srand(time(NULL));
    int *arr = NULL;
    int n, count = 0;
    FILE *fp = fopen("sel2.dat", "a");
    int values[] = {10, 100, 1000, 2000, 5000, 10000, 20000, 40000};

    for (n = 0; n < 8; n++)
    {
        arr = (int *)malloc(sizeof(int) * values[n]);

        for (int j = 0; j < values[n]; j++)
            arr[j] = values[n] - j;
        fprintf(fp, "%d\t%d\n", values[n], selSort(arr, values[n]));

        free(arr);
    }
    fclose(fp);
}