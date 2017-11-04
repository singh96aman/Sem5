#include <stdio.h>
#include <stdlib.h>

void heapify(int h[], int n)
{
	while(n>0)
	{
		int j=n/2;
		if(h[j]<h[n] && j!=0)
		{
			int temp=h[j];
			h[j]=h[n];
			h[n]=temp;
			n=n/2;
		}
		else break;
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int h[n];
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&(h[i]));
		heapify(h,i);
	}
	for(int i=1; i<=n; i++)
		printf("%d ",h[i]);
}