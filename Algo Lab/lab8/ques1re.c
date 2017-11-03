#include <stdio.h>
#include <stdlib.h>

int opcount=0;

void topdown(int h[], int n)
{
	while(n>0)
	{
		int j=n/2;
		if(h[j]<h[n] && j!=0)
		{
			opcount++;
			int temp = h[j];
			h[j] = h[n];
			h[n] = temp;
			n=n/2;
			j/=2;
		}
		else break;
	}
}

int main()
{
	int i, n, val;
	int h[10];
	printf("\n Enter no of Elements : ");
	scanf("%d",&n);
	printf("\n Enter Elements : ");
	for(i=1; i<=n; i++)
	{	
		scanf("%d",&h[i]);	
		topdown(h,i);
		//printf("\n Successfully entered!\n");
	}
	printf("\n Elements are :\n");
	for(i=1; i<=n; i++)
		printf("%d ",h[i]);
	printf("\n No of Operations is : %d",opcount);	
}