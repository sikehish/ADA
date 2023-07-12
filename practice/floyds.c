#include <stdio.h>
#include <stdlib.h>
int graph[100][100];

int minimum(int a, int b)
{
    int min = (a < b) ? a : b;
    return min;
}

void floyds(int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            int T = graph[i][k];
            for (int j = 0; j < n; j++)
            {
                if (T < graph[i][j])
                    graph[i][j] = minimum(graph[i][j], T + graph[k][j]);
            }
        }
    }
}

void main()
{
    int n, i, j;
    printf("\nEnter the number of vertices:\n");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    floyds(n);

    printf("\nAll pair shortest distance matrix is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }
}

// Enter the number of vertices:
// 4

// Enter the adjacency matrix:
// 0 99 3 99
// 2 0 99 99
// 99 7 0 1
// 6 99 99 0

// All pair shortest distance matrix is:
// 0  10  3  4
// 2  0  5  6
// 7  7  0  1
// 6  16  9  0