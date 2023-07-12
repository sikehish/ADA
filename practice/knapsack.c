#include <stdio.h>
#include <stdlib.h>

int knap[100][100];

int maxi(int x, int y)
{
    return x > y ? x : y;
}

int knapsack(int n, int weight[], int values[], int wt)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= wt; j++)
        {
            if (i == 0 || j == 0)
                knap[i][j] = 0;
            else if (weight[i - 1] > j)
                knap[i][j] = knap[i - 1][j];
            else
                knap[i][j] = maxi(knap[i - 1][j], values[i - 1] + knap[i - 1][j - weight[i - 1]]);
        }
    }
    return knap[n][wt];
}

void composition(int n, int weight[], int wt)
{
    int rc = wt;
    int num = 0;
    int subset[n];
    for (int i = n; i >= 1; i--)
    {
        if (knap[i][rc] != knap[i - 1][rc])
        {
            subset[num++] = i;
            rc -= weight[i - 1];
        }
        if (rc == 0)
            break;
    }
    printf("Optimal subset is: ");
    for (int i = 0; i < num; i++)
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
    printf("The optimal value is %d\n", knapsack(n, weight, values, capacity));
    composition(n, weight, capacity);
    free(values);
    free(weight);
}

// Enter number of items:
// 4
// Enter capacity:
// 10

// Enter the weight and value of each item:
// Weight Value
// 7 42
// 3 12
// 4 40
// 5 25
// The optimal value is 65
// Optimal subset is: 4 3

// Enter number of items:
// 4
// Enter capacity:
// 5

// Enter the weight and value of each item:
// Weight Value
// 2 12
// 1 10
// 3 20
// 2 15
// The optimal value is 37
// Optimal subset is: 4 2 1