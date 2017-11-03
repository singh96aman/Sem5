#include <stdio.h>
#include <stdlib.h>

void heapify(int h[], int n)
{
	int i, k, v, heapify, j;
	for(i=n/2; i>=1; i--)
	{
		k=i; v=h[k];
		heapify=0;
		while(heapify==0 && 2*k<=n)
		{
			j=2*k;
			if(j<n)
				if(h[j]<h[j+1])
					j++;
			if(v>=h[j])
				heapify=1;
			else{
				h[k]=h[j];
				k=j;
			}
		}
		h[k]=v;
	}
	return;
}
void main()
{
	int h[20], i, n;
	printf("\n Enter No Of Elements : ");
	scanf("%d",&n);
	printf("\n Enter the Elements : ");
	for(i=1; i<=n; i++)
	{
		scanf("%d",&h[i]);
		heapify(h,i);
	}
	printf("\n Display the array \n");
	for(i=1; i<=n; i++)
		printf("%d\t",h[i]);
	printf("\n The heap created : ");
	for(i=1; i<=n; i++)
		printf("%d\t",h[i]);
}
