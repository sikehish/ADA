// DFS Toplogical Sorting

#include <stdio.h>
#include <stdlib.h>
int n, stk[20], tos = -1;

void detect(int graph[][n], int v, int *visited)
{
    visited[v] = 1;
    for (int j = 0; j < n; j++)
    {
        if (graph[v][j] && visited[j])
        {
            printf("Cycle Exists\n");
            exit(0);
        }
        if (graph[v][j] && !visited[j])
        {
            detect(graph, j, visited);
        }
    }
    visited[v] = 0;
}

void dfs(int graph[][n], int v, int *vis)
{
    vis[v] = 1;
    for (int next = 0; next < n; ++next)
    {
        if (graph[v][next] && !vis[next])
        {
            dfs(graph, next, vis);
        }
    }
    stk[++tos] = v;
}

void main()
{
    printf("Enter no of vertices\n");
    scanf("%d", &n);
    int graph[n][n];

    printf("Adjacency matrix\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }
    int *vis = (int *)malloc(sizeof(int) * n);

    int *vis2 = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;  // for detection
        vis2[i] = 0; // for topo sorting
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            detect(graph, i, vis2); // This is optional. If you dont want to detect cycle, then you may skip this function and declaration of vis2 array
            dfs(graph, i, vis);
        }
    }

    printf("Topological sorting\n");
    for (int i = tos; i >= 0; --i)
        printf("%c ", stk[i] + 65);
    printf("\n");

    free(vis);
}