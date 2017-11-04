#include <stdio.h>

// Use  other heap function
void heapify(int h[], int n, int i)
{
	int l=2*i+1;
	int r=2*i+2;
	int m=i;
	if(l<n && h[l]>h[m])
		m=l;
	if(r<n && h[r]>h[m])
		m=r;
	if(m!=i)
	{
		int t=h[i];
		h[i]=h[m];
		h[m]=t;
		heapify(h,n,m);
	}
}

void makeheap(int h[], int n)
{
	for(int i=n/2-1; i>=0; i--)
	{
		heapify(h,n,i);
	}
}

void minheap(int h[], int n)
{
	for(int i=n/2-1; i>=0; i--)
	{
	int l=2*i+1;
	int r=2*i+2;
	int m=i;
	if(l<n && h[l]<h[m])
		m=l;
	if(r<n && h[r]<h[m])
		m=r;
	if(m!=i)
	{
		int t=h[i];
		h[i]=h[m];
		h[m]=t;
		heapify(h,n,m);
	}
}
}

int main()
{

	int n;
	scanf("%d",&n);
	int h[n];
	for(int i=0; i<n; i++)
		scanf("%d",&(h[i]));
	makeheap(h,n);
	//for(int i=0; i<n; i++)
	//	printf("%d ",h[i]);
	/*int del=6;
	for(int i=0; i<n; i++)
	{
		if(h[i]==del)
		{
			for(int j=i; j<n; j++)
			{
				h[j]=h[j+1];
			}
			n--;
		}
	}
	makeheap(h,n);
	for(int i=0; i<n; i++)
		printf("%d ",h[i]);*/
	minheap(h,n);
	for(int i=0; i<n; i++)
		printf("%d ",h[i]);

}