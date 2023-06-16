

//Implementation of DFS algorithm
#include<stdio.h>
#include<stdlib.h>
int a[10][10],visited[10],n,acyclic=1;
int ccount=0, flag=0;
void dfs(int v, int P)
{
 int i;
 visited[v]=1;
if(P!=-1) printf("->%d",v);
 for(i=0;i<n;i++)
 {
	
  //printf("\n%d<-->%d",v,i);
  if(a[v][i])
   {
    if(visited[i] && (i!=P) && (i!=v))
     {
       acyclic=0;
	}
       if(a[v][i] && !visited[i]) dfs(i,v);
   }
 }
}
void connectandcyclic()
{
 int count=0;
 for(int i=0;i<n;i++) if(visited[i]) count++;

 if(flag==0)
  printf("\nGraph is connected");
 else
  printf("\nGraph is not connected");
 if(acyclic)
  printf("\nGraph is acyclic");
 else
  printf("\nGraph is cyclic");
}
void main()
{
 int i,j;
 int start;
 printf("Enter the number of vertices:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
  visited[i]=0;
 printf("enter the adjacency matrix\n");
 for(i=0;i<n;i++){
  for(j=0;j<n;j++){
   scanf("%d",&a[i][j]);}printf("\n");}
 printf("Enter starting vertex");
 scanf("%d",&start);
	printf("Graph:%d", start);
dfs(start,-1);
 for (i=0;i<n;i++)
 { 
   if(visited[i]==0)
   {
	flag=1;
printf("\nGraph:%d", i);
/*printf("In main, Visited nodes are: \n");
for(int j=0; j<n; j++) printf("%d ", visited[j]);printf("\n");*/
     dfs(i,-1);
   }
 }
 connectandcyclic();
}
   


/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_SIZE 4
#define MAX_SIZE 10

void generateMatrix(int size, int matrix[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 2;  // Generate random 0 or 1
        }
    }
}

void printMatrix(int size, int matrix[size][size]) {
    printf("Matrix %dx%d:\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));  // Initialize random seed

    for (int size = MIN_SIZE; size <= MAX_SIZE; size++) {
        int matrix[size][size];
        generateMatrix(size, matrix);
        printMatrix(size, matrix);
    }

    return 0;
}*/

//OUTPUT

// Enter the number of vertices:4
// enter the adjacency matrix
// 0 1 1 0

// 1 0 1 0

// 1 1 0 0

// 0 0 0 0

// Enter starting vertex0
// Graph:0->1->2
// Graph:3
// Graph is not connected
// Graph is cyclic
