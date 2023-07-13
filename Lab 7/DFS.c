#include <stdio.h>
#include <stdlib.h>

int arr[100][100], visited[100], n, acyclic = 1;
int count = 0, flag = 0;

void genData(int ch)
{
    printf("Graph is\n");
    if (ch == 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == i + 1)
                    arr[i][j] = 1;
                else
                    arr[i][j] = 0;
                printf("%d\t", arr[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                    arr[i][j] = 0;
                else
                    arr[i][j] = 1;
                printf("%d\t", arr[i][j]);
            }
            printf("\n");
        }
    }
    printf("\n");
}

void dfs(int v, int P)
{
    visited[v] = 1;
    printf("%d--> ", v);
    for (int i = 0; i < n; i++)
    {
        if (arr[v][i])
        {
            count++;
            if (!visited[i])
                dfs(i, v);
            else if (visited[i] && i != P)
                acyclic = 0;
        }
    }
}

void connectandcyclic()
{
    if (flag == 0)
        printf("\nGraph is connected\n");
    else
        printf("\nGraph is not connected\n");
    if (acyclic)
        printf("Graph is acyclic\n");
    else
        printf("Graph is cyclic\n");
}

void main()
{
    FILE *fptr = fopen("dfs.txt", "a");
    int i, j;
    n = 4;
    while (n <= 8)
    {
        // best case
        for (i = 0; i <= n; i++)
            visited[i] = 0;
        genData(0);
        acyclic = 1;
        flag = 0;
        printf("Graph: ");
        count = 0;
        dfs(0, -1);
        for (i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {

                flag = 1;
                printf("\nGraph ");
                dfs(i, -1);
            }
        }
        connectandcyclic();
        fprintf(fptr, "%d\t%d\t", n, count);

        // worst case
        count = 0;
        acyclic = 1;
        flag = 0;
        for (i = 0; i < n; i++)
            visited[i] = 0;
        genData(1);
        printf("Graph: ");
        dfs(0, -1);
        for (i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                flag = 1;
                printf("\nGraph ");
                dfs(i, -1);
            }
        }
        connectandcyclic();
        fprintf(fptr, "%d\n", count);
        n = n + 1;
    }
}