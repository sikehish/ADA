#include <stdio.h>

void main()
{

    int i, j, edges = 0;
    int a, b, min, min_cost = 0;
    int cost[50][50], n, visited[50] = {0};

    // Taking graph as input
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    // Finding minimum cost
    visited[0] = 1;

    while (edges < n - 1) // in a minimum spanning tree(MST), edges=vertices-1
    {
        min = 9999;
        for (i = 0; i < n; i++) // traversing the list of vertices and searching for src vertices i.e traversed/visited vertices
        {
            if (visited[i]) // checking if the source vertex is visited, as an outgoing edge is possible only when the src vertex is traversed
            {
                for (j = 0; j < n; j++) // finding destination vertex
                {
                    if (min > cost[i][j] && !visited[j]) // ensuring that destination vertex is unvisited else if both src and destination vertices are visited then it'll result in a cycle
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        printf("%d-->%d | Cost: %d\n", a, b, min);
        visited[b] = 1; // marking destination vertex as visited
        min_cost += min;
        edges++;
    }

    printf("Minimum Cost: %d\n", min_cost);
}