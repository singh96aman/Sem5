#include <stdio.h>
#include <stdlib.h>

int n=4;

int place(int x[n], int k)
{
	for(int i=1; i<k; i++)
	{
		if((x[i]==x[k])||(abs(i-k)))
			return 0;
	}
	return 1;
}

void display(int x[10])
{
	char a[10][10];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			a[i][j]='X';
	for(int i=1; i<=n; i++)
		a[i][x[i]]='Q';
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
			printf("%c ",a[i][j]);
		printf("\n");
	}

}

void queens()
{
	int x[10], count=0, k=1;
	x[k]=0;
	while(k!=0)
	{
		//printf("\n hello");
		x[k]=x[k]+1;
		while(x[k]<=n && (!place(x,k)))
			x[k]=x[k]+1;
		//printf("\n hello");
		printf("%d\n",x[k]);
		if(x[k]<=n)
		{
			printf("\n hello");
			if(k==n)
			{
				count++;
				printf("\n Solution %d\n",count);
				display(x);
			}
			else{
				k++;
				x[k]=0;
			}
		}
		else
			k--;
	}
	return;
}


int main()
{
	queens();
}