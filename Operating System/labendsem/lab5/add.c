#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

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