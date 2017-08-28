#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int checkPrimeNumber(int num)
{
	for(int i=2; i<num/2; i++){
		if(num%i==0)
			return 0;
	}
	return 1;
}

void *child_thread(void *arr)
{

	int *val=arr;
	int first = val[0], second = val[1];
	val = malloc(sizeof(int)*(second-first+1));
	int i=1;
	while(first<=second){
		if(checkPrimeNumber(first))
			{val[i]=first;
			i++;}
			first++;
	}
	val[0]=i;
	return (void *)val;
}

int main(){
	int *val;
	void *temp;
	val = (int*) malloc(sizeof(int)*2);
	pthread_t thread;
	scanf("%d",&val[0]);
	scanf("%d",&val[1]);
	pthread_create(&thread,0,&child_thread,(void*)val);
	pthread_join(thread, &temp);
	val=temp;
	for(int i=1; i<val[0]; i++)
		printf("%d ",val[i]);
}
