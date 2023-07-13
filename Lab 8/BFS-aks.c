// BFS
//  Online C compiler to run C program online
#include <stdio.h>
int graph[10][10], visited[10] = {0}, acyclic = 1, n, count = 0, q[10], f = 0, r = -1;
void createGraph()
{
    printf("Enter no of vertices\n");
    scanf("%d", &n);
    printf("Enter the edges\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
}
void bfs(int x)
{
    visited[x] = 1;
    for (int i = 0; i < n; i++)
    {
        if (graph[x][i] && !visited[i])
        {
            printf("%d-->%d\n", x, i);
            q[++r] = i;
        }
        if (graph[x][i] && visited[i])
        {
            acyclic = 0;
        }
    }
    if (f <= r)
    {
        bfs(q[f++]);
    }
}
int main()
{
    createGraph();
    bfs(0);
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            count++;
    }

    if (acyclic)
    {
        printf("Acyclic\n");
    }
    printf("%d", count);
    if (count == n)
    {
        printf("Connected\n");
    }
    return 0;
}
