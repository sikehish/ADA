#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

int knap[SIZE][SIZE];
int weights[SIZE], values[SIZE];

int maximum(int a, int b)
{
    int max = (a > b) ? a : b;
    return max;
}

int knapsack(int i, int j)
{

    if (knap[i][j] == -1)
    {
        if (weights[i - 1] > j)
            knap[i][j] = knapsack(i - 1, j);
        else
            knap[i][j] = maximum(knapsack(i - 1, j), values[i - 1] + knapsack(i - 1, j - weights[i - 1]));
    }
    return knap[i][j];
}

void composition(int n, int wt)
{
    int rc = wt;
    printf("Composition is : ");
    for (int i = n; i >= 1; i--)
    {
        if (knap[i][rc] != knap[i - 1][rc])
        {
            printf("%d ", i);
            rc -= weights[i - 1];
        }
        if (rc == 0)
            break;
    }
    printf("\n");
}

void main()
{
    int n, capacity;
    printf("Enter the number of items\n");
    scanf("%d", &n);
    printf("Enter the capacity\n");
    scanf("%d", &capacity);

    printf("Enter the weights and values\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &weights[i], &values[i]);
    }

    int i, j;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
                knap[i][j] = 0;
            else
                knap[i][j] = -1;
        }
    }

    knapsack(n, capacity);
    printf("\nThe optimum knapsack value is: %d\n", knap[n][capacity]);
    composition(n, capacity);
}
