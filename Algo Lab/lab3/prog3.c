#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void checkbits(int *set, int a, int b, int n){
	int pow_set_size=pow(2,n);
	int i=0;
	for(i=n-1; i>=0; i--)
		if((a & 1<<i))
			printf("%d ",set[i]);
		printf(" , ");
	for(i=n-1; i>=0; i--)
		if((b & 1<<i))
			printf("%d ",set[i]);
	printf("\n");	
}

void PrintPowerSet(int *set,int set_size){
	int pow_set_size=pow(2,set_size);
	int counter, j, i;
	int *sum = (int *)malloc(sizeof(int)*pow_set_size);
	for(j=0; j<pow_set_size; j++)
		sum[j]=0;

	for(counter=0; counter<pow_set_size; counter++){
		for(j=0; j<set_size; j++){
			if(counter & (1<<j))
				sum[counter]+=set[j];
				//printf("%d",set[j]);
		}
	}
	for(i=0; i<pow_set_size; i++)
		for(j=0; j<pow_set_size; j++){
			if(sum[i]==sum[j] && sum[pow_set_size-1]==(sum[i]+sum[j]) && i!=j){
				checkbits(set,i,j,set_size);
			}
		}
}
int main()
{
	int set[] = {1,2,3,4};
	PrintPowerSet(set,4);
	return 0;
}