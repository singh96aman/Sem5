#include <stdio.h>
#include <stdlib.h>

void bubblesort(int arr[], int n)
{
	for(int i=0; i<n-1; i++)
		for(int j=0; j<n-i-1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
}

int main()
{
	int arr[] = {4,7,1,3,8};
	int n=5;
	bubblesort(arr,5);
	for(int i=0; i<n; i++)
		printf("%d ",arr[i]);
}