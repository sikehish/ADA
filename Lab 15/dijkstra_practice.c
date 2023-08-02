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

// OUTPUT
//  Enter the number of nodes
//  7
//  Enter the cost matrix
//  0 2 6 0 0 0 0
//  2 0 0 5 0 0 0
//  6 0 0 8 0 0 0
//  0 5 8 0 10 15 0
//  0 0 0 10 0 6 2
//  0 0 0 15 6 0 6
//  0 0 0 0 2 6 0
//  Enter the source node
//  1
//  0 -> 1 = 2
//  0 -> 2 = 6
//  0 -> 3 = 7
//  0 -> 4 = 17
//  0 -> 5 = 22
//  0 -> 6 = 19

// Enter the total number of nodes: 5
// Read the cost matrix:
// 0 2 4 1 0
// 2 0 0 3 10
// 4 0 0 2 0
// 1 3 2 0 7
// 0 10 0 7 0
// Enter the source vertex: 1
// Shortest path from 1 is:
// 1 -> 2 = 2
// 1 -> 3 = 3
// 1 -> 4 = 1
// 1 -> 5 = 8