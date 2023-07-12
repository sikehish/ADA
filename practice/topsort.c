#include <stdio.h>
#include <stdlib.h>

void dfs(int n, int arr[][n], int src, int *vis, int *stk, int *stop)
{
    vis[src] = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[src][i] && !vis[i])
        {
            dfs(n, arr, i, vis, stk, stop);
        }
    }
    stk[++(*stop)] = src;
    // printf("\n%d %d\n", *stop, src);
}

void main()
{
    int n;
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    int graph[n][n], vis[n], stk[n], stop = -1;
    printf("Enter the adjacency matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
        vis[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(n, graph, i, vis, stk, &stop);
    }
    printf("Topological sorting\n");
    for (int i = stop; i >= 0; --i)
        printf("%c\t", stk[i] + 65);
}

// Enter the number of vertices
// 8
// Enter the adjacency matrix
// 0 0 0 1 0 0 0 0
// 1 0 0 1 0 0 0 0
// 0 0 0 0 0 0 0 0
// 0 0 1 0 1 0 0 0
// 0 0 0 0 0 0 0 0
// 0 0 0 0 1 0 0 0
// 0 0 0 1 0 1 0 0
// 0 0 0 0 0 1 0 0
// Topological sorting
// H       G       F       B       A       D       E       C