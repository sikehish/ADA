#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int graph[MAX][MAX], visited[MAX] = {0}, visited2[MAX] = {0}, stk[MAX], top = -1;

void topo(int src, int n)
{
    visited[src] = 1;
    for (int i = 0; i < n; i++)
    {
        if (graph[src][i] && !visited[i])
            topo(i, n);
    }
    stk[++top] = src;
}

void detect(int v, int n)
{
    visited2[v] = 1;
    for (int j = 0; j < n; j++)
    {
        if (graph[v][j] && visited2[j])
        {
            printf("Cycle Exists\n");
            exit(0);
        }
        if (graph[v][j] && !visited2[j])
        {
            detect(j, n);
        }
    }
    visited2[v] = 0;
}
void main()
{
    int n;
    printf("Enter no of vertices\n");
    scanf("%d", &n);

    printf("Adjacency matrix\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            detect(i, n); // This is optional. If you dont want to detect cycle, then you may skip this function and declaration of vis2 array
            topo(i, n);
        }
    }

    printf("Topological sorting\n");
    for (int i = top; i >= 0; --i)
        printf("%c ", stk[i] + 65);
    printf("\n");
}

// Enter no of vertices
// 8
// Adjacency matrix
// 0 0 0 1 0 0 0 0
// 1 0 0 1 0 0 0 0
// 0 0 0 0 0 0 0 0
// 0 0 1 0 1 0 0 0
// 0 0 0 0 0 0 0 0
// 0 0 0 0 1 0 0 0
// 0 0 0 1 0 1 0 0
// 0 0 0 0 0 1 0 0
// Topological sorting
// H G F B A D E C