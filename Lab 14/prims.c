#include <stdio.h>

void main()
{

    int i, j, edges = 0;
    int a, b, min, min_cost = 0;
    int cost[50][50], n, visited[50] = {0};

    // Taking graph as input
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    // Finding minimum cost
    visited[0] = 1;
    while (edges < n - 1)
    {
        min = 9999;
        for (i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (j = 0; j < n; j++)
                {
                    if (min > cost[i][j] && !visited[j])
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        printf("%d-->%d | Cost: %d\n", a, b, min);
        visited[b] = 1;
        min_cost += min;
        edges++;
    }

    printf("Minimum Cost: %d\n", min_cost);
}