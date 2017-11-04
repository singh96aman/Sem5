#include <stdio.h>
#include <stdlib.h>

void selectionsort(int a[], int n)
{
	for(int i=0; i<n; i++)
	{
		int min=99999, k;
		for(int j=i; j<n; j++)
			if(min>a[j])
			{
				min=a[j];
				k=j;
			}
		int temp = a[i];
		a[i]=a[k];
		a[k]=temp;
	}
}

int main()
{
	int arr[]={4,1,7,2,5};
	int n=5;
	selectionsort(arr,n);
	for(int i=0; i<n; i++)
		printf("%d ",arr[i]);
}