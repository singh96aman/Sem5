#include <stdlib.h>
#include <stdio.h>
int n=3;

// It is not possible to color a cycle graph with odd cycle using two colors.
void bfs(int arr[n][n], int v)
{
	int i;
	int visited[n], color[n], k=0, counter=0; 
	for(i=0; i<n; i++)
		visited[n]=0;
	int queue[n];
	int f=-1, r=-1;
	queue[++r]=v;
	visited[v]=1;
	color[k]=counter;
	counter=1; //flip
	while(f<=r)
	{
		int val=queue[++f];
		for(int j=0; j<n; j++)
		{
			if(visited[j]==0 && arr[i][j]==1)
			{
				queue[++r]=j;
				visited[j]=1;
				color[j]=counter;
			}
		}
		if(counter==0)
			counter=1;
		else
			counter=0;
	}
	for(i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			if(color[i]==color[j] && i!=j && arr[i][j]==1)
			{
				printf("\n Not bipartite");
				return;
			}
		}
	printf("\n bipartite graph");
}

int main()
{
	int arr[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d",&(arr[i][j]));
    bfs(arr,0);
}