// Floyd's Algorithm
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int graph[MAX][MAX];

int minimum(int a, int b)
{
    int min = (a < b) ? a : b;
    return min;
}

void floyd(int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            int T = graph[i][k];
            for (int j = 1; j <= n; j++)
            {
                if (graph[i][j] > T)
                    graph[i][j] = minimum(graph[i][j], (T + graph[k][j]));
            }
        }
    }
}

void main()
{
    int n, i, j;
    printf("\nEnter the number of vertices:\n");
    scanf("%d", &n);
    printf("\nEnter 99 for representing infinity.\n");
    printf("\nEnter the weight matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    floyd(n);

    printf("\nAll pair shortest distance matrix is:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }
}