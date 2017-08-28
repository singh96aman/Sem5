#include<pthread.h>
#include<stdio.h>
void *child_thread(void *arr)
{

	int *sum=arr;
	int finalsum=0;
	int size = sum[0];
	for(int i=1; i<=size; i++){
		finalsum+=sum[i];
		}
	return (void *)finalsum;
}

int main(){
	pthread_t thread;
	int size, j=1;
	scanf("%d",&size);
	int *arr;
	void *val;
	arr = (int *) malloc(sizeof(int)*size+1);
	arr[0]=size;
	int n=size;
	while(n>0)
	{
		scanf("%d",&arr[j]);
		j++;
		n--;
	}
	pthread_create(&thread,0,&child_thread,(void*)arr);
	pthread_join(thread, &val);
	printf("%d\n",val);
}
