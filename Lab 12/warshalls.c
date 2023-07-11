// Warshall's Algorithm
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int graph[MAX][MAX];

void warshall(int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                graph[i][j] = (graph[i][j] || (graph[i][k] && graph[k][j]));
            }
        }
    }
}

void main()
{
    int n, i, j;
    printf("\nEnter the number of vertices:\n");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    warshall(n);

    printf("\nTransitive closure matrix is:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }
}