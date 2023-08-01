#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

int cost[SIZE][SIZE], dist[SIZE];

void dijikstra(int src, int n)
{
    int visited[n];

    for (int i = 0; i < n; i++)
    {
        dist[i] = cost[src][i];
        visited[i] = 0;
    }

    dist[src] = 0;
    visited[src] = 1;

    int completed = 1;
    while (completed < n)
    {
        int min = 999;
        int v = -1;
        for (int i = 0; i < n; i++)
        {
            if (dist[i] < min && !visited[i])
            {
                v = i;
                min = dist[i];
            }
        }

        visited[v] = 1;

        for (int i = 0; i < n; i++)
        {
            if (dist[i] > dist[v] + cost[v][i])
                dist[i] = dist[v] + cost[v][i];
        }
        completed++;
    }
}

void main()
{
    int n, src;
    printf("Enter the number of nodes\n");
    scanf("%d", &n);

    printf("Enter the cost matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("Enter the source node\n");
    scanf("%d", &src);
    src--;

    dijikstra(src, n);

    for (int i = 0; i < n; i++)
    {
        if (i != src)
            printf("%d -> %d = %d\n", src, i, dist[i]);
    }
}