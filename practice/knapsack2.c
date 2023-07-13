#include <stdio.h>
#include <stdlib.h>

int knap[100][100];

int maxi(int x, int y)
{
    return x > y ? x : y;
}

int knapsack(int i, int j, int *weights, int *values)
{

    if (knap[i][j] < 0)
    {
        if (weights[i - 1] > j)
            knap[i][j] = knapsack(i - 1, j, weights, values);
        else
            knap[i][j] = maxi(knapsack(i - 1, j, weights, values), values[i - 1] + knapsack(i - 1, j - weights[i - 1], weights, values));
    }
    return knap[i][j];
}

void composition(int n, int *weights, int wt)
{
    int RC = wt;
    int subset[n];
    int i = n, j = 0;
    while (i >= 1)
    {
        if (knap[i][RC] != knap[i - 1][RC])
        {
            subset[j++] = i;
            RC -= weights[i - 1];
        }
        if (RC == 0)
            break;

        i--;
    }
    printf("Subsets are: ");
    for (int i = 0; i < j; i++)
    {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

void main()
{
    int n, capacity, *values, *weight;
    printf("\nEnter number of items:\n");
    scanf("%d", &n);
    values = (int *)malloc(n * sizeof(int));
    weight = (int *)malloc(n * sizeof(int));
    printf("Enter capacity: \n");
    scanf("%d", &capacity);
    printf("\nEnter the weight and value of each item:\n");
    printf("Weight Value\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &weight[i], &values[i]);
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < capacity + 1; j++)
        {
            if (i == 0 || j == 0)
                knap[i][j] = 0;
            else
                knap[i][j] = -1;
        }
    }
    printf("The optimal value is %d\n", knapsack(n, capacity, weight, values));
    composition(n, weight, capacity);
    free(values);
    free(weight);
}
