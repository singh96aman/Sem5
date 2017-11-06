#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int queueLength=0;
int queue[100];
pthread_mutex_t mutex;
sem_t semaphore;

void *producer()
{
	for(int i=0; i<100; i++)
	{
		pthread_mutex_lock(&mutex);
		queue[queueLength++]=i;
		printf("\n Produced : %d ",i);
		pthread_mutex_unlock(&mutex);
		sem_post(&semaphore);
	}
}

void *consumer()
{
	for(int i=0; i<100; i++)
	{
		if(queueLength==0)
		{
			printf("\n Waiting ");
			sem_wait(&semaphore);
		}
		pthread_mutex_lock(&mutex);
		int consumed=queue[--queueLength];
		printf("\n Counsumed : %d",consumed);
		pthread_mutex_unlock(&mutex);
	}
}

int main()
{
	pthread_t p1, p2;
	pthread_mutex_init(&mutex,0);
	sem_init(&semaphore,0,0);
	pthread_create(&p1, 0, &producer, 0);
	pthread_create(&p2, 0, &consumer, 0);
	pthread_join(p1, 0);
	pthread_join(p2,0);
}