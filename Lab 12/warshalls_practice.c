#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

void warshalls(int graph[][SIZE], int n)
{

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (graph[i][k] == 1)
                for (int j = 0; j < n; j++)
                {
                    graph[i][j] = graph[i][j] || graph[k][j];
                }
        }
    }
}

void main()
{
    int graph[SIZE][SIZE], n;
    printf("Enter the number of vertices\n");
    scanf("%d", &n);

    printf("\nEnter the weight matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    warshalls(graph, n);

    printf("Transitive closure matrix is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Enter the number of vertices
// 4

// Enter the weight matrix:
// 1 1 0 0
// 1 0 1 0
// 1 1 0 0
// 0 1 0 1
// Transitive closure matrix is:
// 1 1 1 0
// 1 1 1 0
// 1 1 1 0
// 1 1 1 1

// Enter the number of vertices
// 4

// Enter the weight matrix:
// 1 1 0 1
// 1 0 1 0
// 1 1 0 0
// 0 1 0 1
// Transitive closure matrix is:
// 1 1 1 1
// 1 1 1 1
// 1 1 1 1
// 1 1 1 1