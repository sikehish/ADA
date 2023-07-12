// Topological sorting using source removal
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void topo(int graph[][MAX], int *indeg, int *vis, int n)
{
    int i, j, k, count = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            indeg[i] += graph[j][i];
        }
    }

    printf("\nThe topological order is:\n");
    while (count < n)
    {
        int pos = -1;
        for (k = 0; k < n; k++)
        {
            if (indeg[k] == 0 && vis[k] == 0)
            {
                printf(" --> %c", k + 65);
                vis[k] = 1;
                pos = k;
                break;
            }
        }

        if (pos == -1)
        {
            printf("It is not a DAG\n");
            return;
        }

        for (i = 0; i < n; i++)
        {
            if (graph[pos][i] == 1)
                indeg[i]--;
        }

        count++;
    }
}

void main()
{
    int graph[MAX][MAX], vis[MAX], indeg[MAX], i, j, k, n;
    printf("\nEnter the number of nodes in the graph:\n");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
        vis[i] = 0;
        indeg[i] = 0;
    }
    topo(graph, indeg, vis, n);
}