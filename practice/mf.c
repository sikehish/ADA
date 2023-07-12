#include <stdio.h>
#include <stdlib.h>
int values[100], weight[100];
int knap[100][100];

int maxi(int x, int y)
{
    return x > y ? x : y;
}

int knapsack(int i, int j)
{
    int val = 0;
    if (knap[i][j] == -1)
    {
        if (weight[i - 1] > j)
            val = knapsack(i - 1, j);
        else
            val = maxi(knapsack(i - 1, j), (values[i - 1] + knapsack(i - 1, j - weight[i - 1])));

        knap[i][j] = val;
    }
    return knap[i][j];
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
    int n, capacity;
    printf("\nEnter number of items:\n");
    scanf("%d", &n);
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
    printf("The optimal value is %d\n", knapsack(n, capacity));
    composition(n, weight, capacity);
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