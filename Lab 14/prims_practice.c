#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

int cost[SIZE][SIZE];

int prims(int src, int n)
{
    int visited[SIZE] = {0};
    int min_cost = 0;
    visited[src] = 1;
    int edges = 0;

    int a, b;
    while (edges < n - 1)
    {
        int min = 999;
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (cost[i][j] < min && !visited[j])
                    {
                        a = i;
                        b = j;
                        min = cost[i][j];
                    }
                }
            }
        }
        visited[b] = 1;
        printf("%c-->%c | Cost: %d\n", a + 65, b + 65, min);
        min_cost += min;
        edges++;
    }

    return min_cost;
}

void main()
{
    int n, src;

    printf("Enter the number of nodes\n");
    scanf("%d", &n);

    printf("Enter the src vertex\n");
    scanf("%d", &src);

    printf("Enter the cost matrix\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }

    src--;
    int min_cost = prims(src, n);
    printf("Minimum Cost: %d\n", min_cost);
}

// Enter the number of nodes
// 5
// Enter the src vertex
// 1
// Enter the cost matrix
// 0 0 3 0 0
// 0 0 10 4 0
// 3 10 0 2 6
// 0 4 2 0 1
// 0 0 6 1 0
// A-->C | Cost: 3
// C-->D | Cost: 2
// D-->E | Cost: 1
// D-->B | Cost: 4
// Minimum Cost: 10