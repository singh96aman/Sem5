#include <stdio.h>

void mergesort(int arr[], int low, int high)
{
	if(low<high)
	{
		int mid = (low + high)/2;
		//printf("%d ",mid);
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}	

int opcount=0;

void merge(int arr[], int low, int mid, int high)
{
	int A[10], B[10], i, j, n1=0, n2=0;
	for(i=low; i<=mid; i++, n1++)
		A[n1]=arr[i];

	for(j=mid+1; j<=high; j++, n2++)
		B[n2]=arr[j];

	//printf("%d %d %d\n",low,mid,high);

	i=0, j=0;
	int k=low;

	while(i<n1 && j<n2)
	{
		opcount++;
		if(A[i]<B[j])
		{	
			arr[k]=A[i];
			k++;
			i++;
		}
		else
		{
			arr[k]=B[j];
			k++;
			j++;
		}
	}

	while(i<n1)
	{
		arr[k] = A[i];
		k++; i++;
	}

	while(j<n2)
	{
		arr[k] = B[j];
		k++; j++;
	}

	//for(i=low, j=0; i<=high; i++,j++)
	// 	arr[i]=C[j];

	//printf("\n The array after Merge Sort is : \n");
	//for(int i=0; i<5; i++)
		//printf("%d ",arr[i]);

}

int main()
{
	int arr[10], n;
	printf("\n Please Enter Array Size : ");
	scanf("%d",&n);
	printf("\n Please Enter the Array : \n");
	for(int i=0; i<n; i++)
		scanf("%d",&arr[i]);
	mergesort(arr,0,n-1);
	printf("\n The array after Merge Sort is : \n");
	for(int i=0; i<n; i++)
		printf("%d ",arr[i]);
	printf("\n Operation Count : %d",opcount);
}