#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int checkPrime(int p)
{
	for(int i=2; i<p/2; i++)
		if(p%i==0)
			return 0;
	return 1;
}

void *findPrime(void *arr)
{
	int *sum=arr;
	int m=sum[0];
	int n=sum[1];
	int k=1;
	int *prime=(int*)malloc(sizeof(int)*10);
	for(int i=m; i<=n; i++)
	{
		if(checkPrime(i))
			{	prime[k]=i; k++;	}
	}
	prime[0]=k-1;
	printf("\n");
	//for(int i=1; i<k; i++)
		//printf("%d \n",prime[i]);
	return (void *) prime;
}

int main()
{
	pthread_t p1;
	int n1=10, n2=20;
	int arr[]={10,20};
	void *a;
	pthread_create(&p1, 0, &findPrime, (void *)arr);
	pthread_join(p1,&a);
	int *prime=a;
	int n=prime[0];
	for(int i=1; i<=n; i++)
		printf("%d ",prime[i]);
}