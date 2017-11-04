#include <stdio.h>
#include <stdlib.h>
int n=5;
void insertionsort(int a[n])
{
	int j;
	for(int i=1; i<n; i++)
	{
		//for(int i=0; i<n; i++)
		//	printf("%d ",a[i]);
		//printf("\n");
		int v=a[i];
		j=i-1;
		while(j>=0 && v<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
	}
}

int main()
{
	int arr[]={5,1,3,2,4};
	insertionsort(arr);
	for(int i=0; i<n; i++)
			printf("%d ",arr[i]);
}