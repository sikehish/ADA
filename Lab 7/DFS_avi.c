
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int n;
int ct = 0, k = 0;
void dfs(int a[][n], int i, int visited[], int *c, int comp[])
{
    *(c) += 1;
    visited[i] = *c;
    k += 1;
    comp[i] = k;
    for (int j = 0; j < n; j++)
    {
        if (visited[j] == 0 && a[i][j] == 1)
        {
            dfs(a, j, visited, c, comp);
        }
    }
}
void dfs_help(int a[][n], int s, int visited[], int *c, int comp[])
{
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        comp[i] = 0;
    }
    for (int i = s; (i % (n + 1)) < n; i++)
    {
        i = i % (n + 1);
        if (visited[i] == 0)
        {
            ct += 1;
            k = 0;
            dfs(a, i, visited, c, comp);
        }
    }
}
int dfs_cyc(int a[][n], int i, int visited[], int *c, int p)
{
    *(c) += 1;
    visited[i] = *c;
    for (int j = i; j < n; j++)
    {
        if (visited[j] == 0 && a[i][j] == 1)
        {
            if (dfs_cyc(a, j, visited, c, i) == 1)
                return 1;
        }
        else
        {
            if (a[i][j] == 1 && i != p)
            {
                return 1;
            }
        }
    }
    return 0;
}
int dfs_cyc_help(int a[][n], int s, int visited[], int *c)
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    for (int i = s; (i % (n + 1)) < n; i++)
    {
        i = i % (n + 1);
        if (visited[i] == 0)
        {
            if (dfs_cyc(a, i, visited, c, -1) == 1)
                return 1;
        }
    }
    return 0;
}
void main()
{
    printf("Enter number of nodes\n");
    scanf("%d", &n);
    int c = 0, s, h, p = 1;
    char m;
    int a[n][n];
    int visited[n];
    int comp[n];
    printf("Enter Graph\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("enter start nodes\n");
    scanf(" %c", &m);
    s = m - 65;
    dfs_help(a, s, visited, &c, comp);
    printf("Traversal\n");
    for (int i = 0; i < n; i++)
        printf("%c\t", visited[i] + 64);
    printf("\n");
    int i = 0;
    printf("Connected components are\n");
    while (i < n)
    {
        h = i + 64;
        printf("Component %d is\n", p);
        do
        {
            printf("%c\t", comp[i] + h);
            i++;
            p++;
        } while (comp[i] != 1 && i < n);
        printf("\n");
    }
    printf("\n");
    c = 0;
    int r = dfs_cyc_help(a, s, visited, &c);
    if (r == 0)
        printf("Acyclic\n");
    else
        printf("Cyclic\n");
    if (ct > 1)
        printf("Disconnected\n");
    else
        printf("Connected\n");
}