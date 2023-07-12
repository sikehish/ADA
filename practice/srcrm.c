#include <stdio.h>
#include <stdlib.h>

void topo(int n, int graph[][n], int indeg[], int vis[])
{

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            indeg[i] += graph[j][i];
        }
    }
    printf("Topological sort using src removal is: ");

    while (count < n)
    {
        int src = -1; // store vertex with indegree 0
        for (int i = 0; i < n; i++)
        {
            if (!indeg[i] && !vis[i])
            {
                printf(" --> %c ", i + 65);
                src = i;
                vis[i] = 1;
                break;
            }
        }
        if (src == -1)
            printf("It is not a DAG\n");

        for (int i = 0; i < n; i++)
        {
            if (graph[src][i])
                indeg[i]--;
        }

        count++;
    }
}

void main()
{
    int i, j, k, n;
    printf("\nEnter the number of nodes in the graph:\n");
    scanf("%d", &n);
    int graph[n][n], vis[n], indeg[n];
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
    topo(n, graph, indeg, vis);
}

// Enter the number of nodes in the graph:
// 8

// Enter the adjacency matrix:
// 0 0 0 1 0 0 0 0
// 1 0 0 1 0 0 0 0
// 0 0 0 0 0 0 0 0
// 0 0 1 0 1 0 0 0
// 0 0 0 0 0 0 0 0
// 0 0 0 0 1 0 0 0
// 0 0 0 1 0 1 0 0
// 0 0 0 0 0 1 0 0
// Topological sort using src removal is:  --> B  --> A  --> G  --> D  --> C  --> H  --> F  --> E