#include <stdio.h>
#include <stdlib.h>

int arr[100][100], visited[100], n, acyclic = 1, q[100], front = 0, rear = -1;
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

void enqueue(int i)
{
    q[++rear] = i;
}

int dequeue()
{
    return q[front++];
}

int isEmpty()
{
    if (front > rear)
        return 1;
    return 0;
}

void bfs(int v)
{

    enqueue(v);
    visited[v] = 1;
    while (!isEmpty())
    {
        int ele = dequeue();
        printf("-->%c ", ele + 65);
        for (int i = 0; i < n; i++)
        {
            if (arr[ele][i])
            {
                count++;
                if (!visited[i])
                {
                    enqueue(i);
                    visited[i] = 1;
                }
                else
                {
                    acyclic = 0;
                }
            }
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
        printf("Graph is acyclic\n\n");
    else
        printf("Graph is cyclic\n\n");
}

void main()
{
    FILE *fptr = fopen("bfs.txt", "a");
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
        bfs(0);
        for (i = 1; i < n; i++)
        {
            if (visited[i] == 0)
            {

                flag = 1;
                printf("\nGraph ");
                bfs(i);
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
        bfs(0);
        for (i = 1; i < n; i++)
        {
            if (visited[i] == 0)
            {
                flag = 1;
                printf("\nGraph ");
                bfs(i);
            }
        }
        connectandcyclic();
        fprintf(fptr, "%d\n", count);
        n = n + 1;
    }
}