// Knapsac problem bottom up
#include <stdio.h>

int maximum(int a, int b)
{
    int max = (a > b) ? a : b;
    return max;
}

int knapsac(int wt, int weight[], int value[], int n)
{
    int i, w;
    int knap[n][wt];
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= wt; w++)
        {
            if (i == 0 || w == 0)
            {
                knap[i][w] = 0;
            }
            if (wt - weight[i - 1] >= 0)
            {
                knap[i][w] = maximum((value[i - 1] + knap[i - 1][wt - weight[i - 1]]), knap[i - 1][w]);
            }
            else
            {
                knap[i][w] = knap[i - 1][w];
            }
        }
    }

    return knap[n][wt];
}

int main()
{
    int n, capacity, *value, *weight;
    printf("\nEnter number of items:\n");
    scanf("%d", &n);
    value = (int *)malloc(n * sizeof(int));
    weight = (int *)malloc(n * sizeof(int));
    printf("\nEnter the value and weight of each item:\n");
    printf("Value  Weight\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &value[i], &weight[i]);
    }
    printf("\nThe optimum knapsac value is: %d\n", knapsac(capacity, weight, value, n));
    return 0;
}