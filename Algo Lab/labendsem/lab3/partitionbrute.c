#include <stdio.h>
#include <stdlib.h>

int checkbits(int set[], int a, int b, int n)
{
	for(int i=n-1; i>=0; i--)
		if(a & (1<<i))
			printf("%d ",set[i]);
	printf("\n");
	for(int i=n-1; i>=0; i--)
		if(b & (1<<i))
			printf("%d ",set[i]);
}

void partition(int set[], int n)
{
	int max_size=pow(2,n);
	int sum[max_size];
	for(int i=0; i<max_size; i++)
		sum[i]=0;
	for(int counter=0; counter<max_size; counter++)
		for(int j=0; j<n; j++)
			if(counter & (1<<j))
				sum[counter]+=set[j];
	for(int i=0; i<max_size; i++)
		for(int j=0; j<max_size; j++)
			if(sum[i]==sum[j] && sum[max_size-1]==(sum[i]+sum[j]))
				checkbits(set,i,j,n);
}

int main()
{
	int set[]={3,6,2,5};
	int n=4;
	partition(set,n);
}