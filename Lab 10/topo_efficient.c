// TOPO SR -> Effecient method using adj matrix
#include <stdio.h>
#include <stdlib.h>
int n, AdjMat[100][100], Queue[20], f = -1, r = -1;
void Enqueue(int i)
{
    if (r == 9)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (f == -1)
        {
            f = 0;
        }
        r++;
        Queue[r] = i;
    }
}
int isEmpty()
{
    if (f > r || f == -1)
    {
        return 1;
    }
    return 0;
}
int Dequeue()
{
    int item;
    if (isEmpty())
    {
        printf("Queue Underflow\n");
    }
    else
    {
        item = Queue[f];
        f++;
    }
    return item;
}
int indegree(int x)
{
    int indeg = 0;
    for (int i = 0; i < n; i++)
    {
        if (AdjMat[i][x])
        {
            indeg++;
        }
    }
    return indeg;
}
void CreateGraph()
{
    printf("Enter No of vertices\n");
    scanf("%d", &n);
    printf("Enter Adjacency Matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &AdjMat[i][j]);
        }
    }
}
int main()
{
    int queue[10], stop = 0, InDeg[10], v;
    CreateGraph();
    for (int i = 0; i < n; i++)
    {
        InDeg[i] = indegree(i);
        if (InDeg[i] == 0)
        {
            Enqueue(i);
        }
    }
    while (!isEmpty() && stop < n)
    {
        v = Dequeue();
        queue[stop++] = v;
        for (int i = 0; i < n; i++)
        {
            if (AdjMat[v][i])
            {
                AdjMat[v][i] = 0;
                InDeg[i] = InDeg[i] - 1;
                if (InDeg[i] == 0)
                {
                    Enqueue(i);
                }
            }
        }
    }
    if (stop < n)
    {
        printf("Cycle");
        exit(1);
    }
    printf("Vertices in Topo Order\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", queue[i]);
    }
    return 0;
}