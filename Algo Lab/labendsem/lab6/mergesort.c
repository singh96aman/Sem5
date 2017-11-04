#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int r, int m)
{
	int a[10], b[10], len1=0, len2=0;
	for(int i=l; i<=m; i++, len1++)
		a[len1]=arr[i];
	for(int i=m+1; i<=r; i++, len2++)
		b[len2]=arr[i];

	int i=0, j=0, k=l;
	while(i<len1 && j<len2)
	{
		if(a[i]<b[j])
		{
			arr[k]=a[i];
			i++; k++;
		}
		else
		{
			arr[k]=b[j];
			j++; k++;
		}
	}

	while(i<len1)
	{
		arr[k]=a[i];
		i++; k++;
	}
	while(j<len2)
	{
		arr[k]=b[j];
		j++; k++;
	}
}

void Mergesort(int arr[], int l, int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		Mergesort(arr,l,m);
		Mergesort(arr,m+1,r);
		merge(arr,l,r,m);
	}
}

int main(){
	int n=5;
	int arr[]={4,1,5,2,3};
	Mergesort(arr,0,4);
	for(int i=0; i<n; i++)
		printf("%d ",arr[i]);
}
