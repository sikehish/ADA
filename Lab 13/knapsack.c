// Knapsac problem bottom up
#include <stdio.h>
#include <stdlib.h>

int maximum(int a, int b)
{
    int max = (a > b) ? a : b;
    return max;
}

int knapsac(int wt, int weight[], int value[], int n)
{
    int i, j;
    int knap[n + 1][wt + 1];
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= wt; j++)
        {
            if (i == 0 || j == 0)
                knap[i][j] = 0;
            else if (j < weight[i - 1])
                knap[i][j] = knap[i - 1][j];
            else
                knap[i][j] = maximum(value[i - 1] + knap[i - 1][j - weight[i - 1]], knap[i - 1][j]);
            printf("%d ", knap[i][j]);
        }
        printf("\n");
    }

    int opt_set[n + 1];

    int rc = wt;
    for (int i = n; i >= 1; i--)
    {
        opt_set[i] = 0;
        if (knap[i][rc] != knap[i - 1][rc])
        {
            opt_set[i] = 1;
            rc = rc - weight[i - 1];
        }

        if (rc == 0)
            break;
    }

    printf("\nThe optimum knapsac value is: %d\n", knap[n][wt]);
    printf("The items part of the optimal set are: ");
    j = n;
    while (j > 0)
    {
        if (opt_set[j] == 1)
            printf("%d ", j);
        j--;
    }
    printf("\n");
}
int main()
{
    int n, capacity, *value, *weight;
    printf("\nEnter number of items:\n");
    scanf("%d", &n);
    value = (int *)malloc(n * sizeof(int));
    weight = (int *)malloc(n * sizeof(int));
    printf("Enter capacity: \n");
    scanf("%d", &capacity);
    printf("\nEnter the value and weight of each item:\n");
    printf("Weight Value\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &weight[i], &value[i]);
    }
    knapsac(capacity, weight, value, n);
    return 0;
}