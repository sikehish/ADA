// Topological sorting using source removal
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void main()
{
    int graph[MAX][MAX], flag[MAX], indeg[MAX], n, i, j, k, count = 0;
    printf("\nEnter the number of nodes in the graph:\n");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
        flag[i] = 0;
        indeg[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            indeg[i] += graph[j][i];
        }
    }

    printf("\nThe topological oreder is:\n");
    while (count < n)
    {
        int pos;
        for (k = 0; k < n; k++)
        {
            if (indeg[k] == 0 && flag[k] == 0)
            {
                printf(" --> %c", k + 65);
                flag[k] = 1;
                pos = k;
                break;
            }
        }

        for (i = 0; i < n; i++)
        {
            if (graph[pos][i] == 1)
                indeg[i]--;
        }

        count++;
    }
}