#include <stdio.h>

int opcount=0;

void swap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

void quicksort(int arr[], int low, int high)
{
	if(low<high)
	{
		int p = partition(arr,low,high);
		quicksort(arr,low,p-1);
		quicksort(arr,p+1,high);
	}
}

int partition(int arr[], int low, int high)
{
	int p=arr[low];
	int i=low, j=high+1;
	while(i<=j)
	{
		while(arr[++i]<=p)
			opcount++;
		opcount++;
		while(arr[--j]>p)
			opcount++;
		opcount++;
		swap(arr,i,j);
	}
	swap(arr,i,j);
	swap(arr,low,j);
	return j;
}

/*
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low-1;
	for(int j=low; j<high; j++)
	{
		opcount++;
		if(arr[j]<pivot) // Base Operation
		{
			i++;
			swap(arr,i,j);
		}
	}
	swap(arr,i+1,high);
	return i+1;
}
*/

int main()
{
	int arr[10], n;
	printf("\n Enter the Array Size : ");
	scanf("%d",&n);
	printf("\n Please Enter the Array : \n");
	for(int i=0; i<n; i++)
		scanf("%d",&arr[i]);
	quicksort(arr,0,n-1);
	printf("\n The new Array is : \n");
	for(int i=0; i<n; i++)
		printf("%d ",arr[i]);

	printf("\nOperation Count : %d",opcount);
}