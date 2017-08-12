#include<stdio.h>
#include<stdlib.h>
int* bubblesort(int *arr, int n){
	int i,j,opcount=0;
	for(i=0; i<n-1; i++)
		for(j=0; j<n-1-i; j++){
			opcount++;
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	printf("\n\nOperation Count : %d\n\n",opcount);
	return arr;
}
int main(){
	int *a;
	int i, n=5;
	for(int j=0;j<4;j++){
		a=(int*)malloc(sizeof(int)*n);
		for(int k=0; k<n; k++)
			a[k]=n-k;
		printf("Elements are\n");
		for(i=0; i<n; i++)
			printf("%d ",a[i]);
		a=bubblesort(a,n);
		printf("Elements after Bubble Sort\n");
		for(i=0; i<n; i++)
			printf("%d ",a[i]);
		printf("\n\n");
		free(a);
		n+=5;
	}
}