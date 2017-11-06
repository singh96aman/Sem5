#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *findSum(void *arr)
{
	int *sum=arr;
	int n=sum[0];
	int total=0;
	for(int i=1; i<=n; i++)
		total+=sum[i];
	return (void *)total;
}

int main()
{
	int n=5;
	int arr[]={54,12,45,23,67};
	int sum[]={5,54,12,45,23,67};
	pthread_t p1;
	void *a;
	pthread_create(&p1,0,&findSum,(void*)sum);
	//printf("\n Hello");
	pthread_join(p1,&a);
	int total=a;
	printf("\n The sum is %d : ",total);
}