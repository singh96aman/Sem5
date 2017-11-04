#include <stdio.h>
#include <stdlib.h>

void heapify(int h[10], int n)
{
	int i, k, v, heapify, j;
	for(i=(n/2); i>=1; i--)
	{
		k=i; v=h[k]; heapify=0;
		while(heapify==0 && 2*k<=n)
		{
			j=2*k;
			if(j<n)
				if(h[j]<h[j+1])
					j+=1;
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

int main()
{
	int n;
	scanf("%d",&n);
	int h[n];
	for(int i=1; i<=n; i++)
		scanf("%d",&(h[i]));
	heapify(h,n);
	for(int i=1; i<=n; i++)
		printf("%d ",h[i]);
}