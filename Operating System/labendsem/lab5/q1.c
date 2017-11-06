#include <pthread.h>
#include <stdio.h>

void *input()
{
	printf("\n Enter a number : ");
	int n;
	scanf("%d",&n);
	return (void*)n;
}

int findfibo(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return (findfibo(n-1) + findfibo(n-2));
}

void *fibo(int n)
{
	int m=findfibo(n);
	return (void*)m;
}

int main()
{
	pthread_t p1, p2;
	int n;
	void *a;
	pthread_create(&p1,0,&input,0);
	pthread_join(p1,&a);
	n=(int)a;
	printf("\nNo input is %d\n",n);
	pthread_create(&p2,0,&fibo,(void*)n);
	pthread_join(p2,&a);
	n=(int)a;
	printf("\nFibonacci Number is : %d\n",n);
}