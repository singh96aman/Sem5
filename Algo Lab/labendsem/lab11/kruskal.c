/* input in the normal 1 ... N way*/
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

typedef struct
{
	int n1,n2,w;
}edges;

int n,e;

int getMin(edges edgeList[], int wtMatrix[][n], int mstFlag[])
{
	int min = INT_MAX;
	int min_edge = -1;
	int i,j;
	for(i=0;i<e;i++)
	{
		if(mstFlag[i]==0 && edgeList[i].w<min)
		{
			min = edgeList[i].w;
			min_edge = i;
		}
	}
	return min_edge;
}

int findRoot(int parent[],int i)
{
	if(parent[i]==i)
		return i;
	return findRoot(parent,parent[i]);
}

void union_util(int parent[],int order[],int x,int y)
{
	int xRoot,yRoot;
	xRoot = findRoot(parent,x);
	yRoot = findRoot(parent,y);

	if(order[xRoot]<order[yRoot])
		parent[xRoot]=yRoot;
	else if(order[xRoot]>order[yRoot])
		parent[yRoot]=xRoot;
	else
	{
		parent[yRoot]=xRoot;
		order[xRoot]+=1;
	}

}

void kruskals(edges edgeList[],int wtMatrix[][n])
{
	edges mstEdgeList[e];
	int mstFlag[e];
	int mstLen = 0;
	int i,j,k;
	for(i=0;i<e;i++)
		mstFlag[i]=0;

	int parent[n],order[n];
	for(i=0;i<n;i++)
	{
		parent[i] = i;
		order[i] = 0;
	}

	while(mstLen < n-1)
	{
		int currEdgeIndex = getMin(edgeList,wtMatrix,mstFlag);
		edges currEdge = edgeList[currEdgeIndex]; 
		mstFlag[currEdgeIndex] = 1;
		int y = findRoot(parent,currEdge.n2);
		int x = findRoot(parent,currEdge.n1);
		if(x!=y)
		{
			mstEdgeList[mstLen++] = currEdge;
			union_util(parent,order,x,y);
		}
	}
	for(i=0;i<mstLen;i++)
	{
		printf("%d %d %d\n",mstEdgeList[i].n1+1,mstEdgeList[i].n2+1,mstEdgeList[i].w);
	}
}


int main()
{
	
	printf("Enter the number of nodes:\n");
	scanf("%d",&n);
	int i,j,k;
	int n1,n2,wt,wtMatrix[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			wtMatrix[i][j]=0;
	printf("Enter the number of edges:\n");
	scanf("%d",&e);
	edges edgeList[e];
	printf("Enter n1,n2 and weight value:\n");
	for(i=0;i<e;i++)
	{
		scanf("%d%d%d",&n1,&n2,&wt);
		edgeList[i].n1 = n1-1;
		edgeList[i].n2 = n2-1;
		edgeList[i].w = wt;
		wtMatrix[n1-1][n2-1]=wt;
		wtMatrix[n2-1][n1-1]=wt;
	}

	printf("Weighted matrix formed is:\n");
	for(i=0;i<n;i++)
		{for(j=0;j<n;j++)
			{printf("%d\t",wtMatrix[i][j]);}
		printf("\n");
	}

	kruskals(edgeList,wtMatrix);
	return 0;
}