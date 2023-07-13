// DFS
//  Online C compiler to run C program online
#include <stdio.h>
int graph[10][10], visited[10] = {0}, acyclic = 1, n, count = 0;
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
void dfs(int i)
{
    visited[i] = 1;
    count++;
    for (int j = 0; j < n; j++)
    {
        if (graph[i][j] && visited[j])
        {
            acyclic = 0;
            printf("%d<-->%d\n", j, j);
        }
        if (graph[i][j] && !visited[j])
        {
            printf("%d-->%d\n", i, j);
            dfs(j);
        }
    }
}

int main()
{
    createGraph();
    dfs(0);
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            count++;
    }

    if (acyclic)
    {
        printf("Acyclic\n");
    }
    if (count == n)
    {
        printf("Connected\n");
    }
    return 0;
}
