#include <stdio.h>

int n=3, e;

int minDistance(int dist[], int SptSet[])
{
	int min=9999;
	int min_index=-1;
	for(int i=0; i<n; i++)
	{
		if(SptSet[i]==0 && dist[i]<=min)
		{
			min=dist[i];
			min_index=i;
		}
	}
	return min_index;
}

void dijkstra(int src, int wtmatrix[10][10])
{
	int dist[n], parent[n], SptSet[n];
	for(int i=0; i<=n; i++)
	{
		SptSet[i]=0;
		dist[i]=9999;
	}
	dist[src]=0;
	parent[src]=0;

	for(int i=0; i<n-1; i++)
	{
		int m=minDistance(dist,SptSet);
		SptSet[m]=1;

		for(int j=0; j<n; j++)
		{
			if(wtmatrix[m][j]!=0 && SptSet[j]==0 && dist[m]!=9999 && (dist[m] + wtmatrix[m][j] < dist[j]))
			{
				dist[j]=dist[m]+wtmatrix[m][j];
				parent[j]=m;
			}
		}
	}
	for(int i=0; i<n; i++)
	{
				//printf("Hello\n");
		if(i==src) continue;
	printf("\n Shortest distance : %d",dist[i]);
	printf("\n");
	}
}

int main()
{
	int wtmatrix[n][n];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			wtmatrix[i][j]=0;
		}
	}
		for(int j=0; j<n; j++)
		{
			int n1, n2, w;
			scanf("%d %d %d",&n1, &n2, &w);
			wtmatrix[n1-1][n2-1]=w;
		}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%d ",wtmatrix[i][j]);
		}
		printf("\n");
	}
	dijkstra(1,wtmatrix);
}