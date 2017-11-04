#include <stdio.h>

void heapify(int a[], int n, int i)
{
	int l=2*i+1;
	int r=2*i+2;
	int m=i;
	if(l<n && a[l]>a[m])
		m=l;
	if(r<n && a[r]>a[m])
		m=r;
	if(m!=i){
		int t=a[i];
		a[i]=a[m];
		a[m]=t;
		heapify(a,n,m);
	}
}

/*void makeheap(int h[], int n)
{
	for(int i=(n/2)-1; i>=0; i++)
		heapify(h,n,i);
}*/

void heapsort(int h[], int n)
{
	for(int i=(n/2)-1; i>=0; i--)
		heapify(h,n,i);

	for(int i=n-1; i>=0; i--)
	{
		int t=h[0];
		h[0]=h[i];
		h[i]=t;
		heapify(h,i,0);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int h[n];
	for(int i=0; i<n; i++)
		scanf("%d",&(h[i]));
	//makeheap(h,n);
	heapsort(h,n);
	for(int i=1; i<=n; i++)
		printf("%d ",h[i]);
}