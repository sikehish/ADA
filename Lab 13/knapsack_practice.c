#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

int knap[SIZE][SIZE];

int maximum(int a, int b)
{
    int max = (a > b) ? a : b;
    return max;
}

int knapsack(int n, int capacity, int values[], int weights[])
{

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
                knap[i][j] = 0;
            else if (weights[i - 1] > j)
                knap[i][j] = knap[i - 1][j];
            else
                knap[i][j] = maximum(values[i - 1] + knap[i - 1][j - weights[i - 1]], knap[i - 1][j]);
            printf("%d ", knap[i][j]);
        }
        printf("\n");
    }

    printf("\nThe optimum knapsack value is: %d\n", knap[n][capacity]);
    return knap[n][capacity];
}

void composition(int n, int wt, int weights[])
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
    int n, capacity, weights[SIZE], values[SIZE];
    printf("Enter the number of items\n");
    scanf("%d", &n);
    printf("Enter the capacity\n");
    scanf("%d", &capacity);

    printf("Enter the weights and values\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &weights[i], &values[i]);
    }

    knapsack(n, capacity, values, weights);
    composition(n, capacity, weights);
}

// Enter the number of items
// 4
// Enter the capacity
// 10
// Enter the weights and values
// 7 42
// 3 12
// 4 40
// 5 25
// 0 0 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 42 42 42 42
// 0 0 0 12 12 12 12 42 42 42 54
// 0 0 0 12 40 40 40 52 52 52 54
// 0 0 0 12 40 40 40 52 52 65 65

// The optimum knapsack value is: 65
// Composition is : 4 3

// Enter the number of items
// 4
// Enter the capacity
// 5
// Enter the weights and values
// 2 12
// 1 10
// 3 20
// 2 15
// 0 0 0 0 0 0
// 0 0 12 12 12 12
// 0 10 12 22 22 22
// 0 10 12 22 30 32
// 0 10 15 25 30 37

// The optimum knapsack value is: 37
// Composition is : 4 2 1