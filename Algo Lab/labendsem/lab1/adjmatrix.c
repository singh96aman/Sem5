#include <stdio.h>
#include <stdlib.h>

void print(int matrix[4][4], int n)
{
	/*printf("\n");
	int i, j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%d ",matrix[i][j]);
		printf("\n");
	}*/

	int v=0;
	int visited[n];
	for(int i=0; i<n; i++)
	{
		printf("%d -> ",i);
		for(int j=0; j<n; j++)
			if(matrix[i][j]==1)
				printf("%d -> ",j);
		printf("\n");
	}
}

int main()
{
	int i, j, n=4;
	int matrix[n][n];
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%d",&(matrix[i][j]));

	/*for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%d",matrix[i][j]);
		printf("\n");
	}*/

	print(matrix, n);
}