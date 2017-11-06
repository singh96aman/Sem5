#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t wrt, mutex;
int readcount=0;
int queueLength=0;
int queue[100];

void *writer()
{
	for(int i=0; i<100; i++)
	{
		sem_wait(&wrt);
		queue[queueLength++]=i;
		printf("\n Produced : %d ",i);
		sem_post(&wrt);
	}
}

void *reader()
{
	for(int i=0; i<100; i++)
	{
		sem_wait(&mutex);
		readcount++;
		if(readcount==1)
			sem_wait(&wrt);
		sem_post(&mutex);
		int consumed=queue[--queueLength];
		printf("\n Counsumed : %d",consumed);
		sem_wait(&mutex);
		readcount--;
		if(readcount==0)
			sem_post(&wrt);
	}
}

int main()
{
	pthread_t p1, p2;
	sem_init(&wrt,0,0);
	sem_init(&mutex,0,0);
	pthread_create(&p1, 0, &reader, 0);
	pthread_create(&p2, 0, &writer, 0);
	pthread_join(p1, 0);
	pthread_join(p2,0);
}