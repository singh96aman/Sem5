#include <stdio.h>
#include <stdlib.h>

void print(int matrix[40][40], int n)
{
	int i,v=0;
	int visited[n];
	for(i=0; i<n; i++)
}

int main()
{
	int i, j, n=4;
	int matrix[40][40];
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%d",matrix[i][j]);

	print(matrix, n);
}