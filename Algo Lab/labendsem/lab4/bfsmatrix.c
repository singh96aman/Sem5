#include <stdlib.h>
#include <stdio.h>

int n=4;

int push[20], pop[20];
int push_i=0, pop_i=0;

void bfs(int arr[n][n], int visited[n], int v)
{
	int queue[n];
	int f=-1, r=-1;
	queue[++r]=v;
	printf("%d",v);
	visited[v]=1;
	while(f<=r)
	{
		int k=queue[++f];
		for(int i=0; i<n; i++)
		{
			if(visited[i]==0 && arr[k][i]==1)
				{
					visited[i]=1;
					queue[++r]=i;
					printf("%d ",i);
				}
		}
	}
}
int main()
{
	int arr[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d",&(arr[i][j]));
    
    int visited[n];
    for(int i=0; i<n; i++)
        visited[i]=0;

    bfs(arr,visited,0);
}