#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int n,stk[20],tos=-1,flag=0;
int **create(int a[n][n],int n)
{
	int *p;
	p=(int*)malloc(sizeof(int)*n*n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			
			p[i][j]=(int*)malloc(sizeof(int));
		}
	}
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
			{
				p[i][j]=0;
			}
			else
			{
				p[i][j]=rand()%2;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",p[i][j]);
		}
	}
	return p;
}
void dfs(int graph[][n],int curr,int *vis){
	vis[curr]=1;
	for(int next=0;next<n;++next)
		{
			if(graph[curr][next])
			{
				if(vis[next]!=0)
				{
					//printf("Back edge exists no solution\n");
					//exit(0);	
					flag=1;
				}	
				else 
				{	
					dfs(graph,next,vis);
				}
			}
		stk[++tos]=curr;
	}	
}
void main(){
	//printf("Enter no of vertices\n");
	//scanf("%d",&n);
	for(int n=4;n<9;n++){
     do{
//	int *graph=(int*)malloc(sizeof(int)*n);
	printf("Adjacency matrix>>\n");
	//for(int i=0;i<n;i++){
		//or(int j=0;j<n;j++)
			//scanf("%d",&graph[i][j]);
	//}
	//int graph[n][n];
	int **graph;
	//graph=malloc(sizeof(int)*n*n);
	graph=create(graph,n);
	int *vis=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		if(!vis[i])
			dfs(graph,i,vis);
	}
	//if(flag==1)
	//{
		//printf("cycle exists no solution\n");
		//exit(0);
	//}
	}while(flag!=0);
	printf("Topological sorting\n");
	for(int i=tos;i>=0;--i)
		printf("%d\n",stk[i]);
	
	}
}
