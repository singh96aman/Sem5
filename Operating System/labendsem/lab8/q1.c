#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int produce=0, consume=0;
int queue[100];
pthread_mutex_t mutex;
sem_t semaphore;

void *producer()
{
	for(int i=0; i<500; i++)
	{
		if(produce==consume+10)
			sem_wait(&semaphore);
		pthread_mutex_lock(&mutex);
		queue[produce++]=i;
		printf("\n Produced : %d ",i);
		pthread_mutex_unlock(&mutex);
		sem_post(&semaphore);
	}
}

void *consumer()
{
	for(int i=0; i<500; i++)
	{
		if(produce==consume)
			sem_wait(&semaphore);
		pthread_mutex_lock(&mutex);
		int consumed=queue[consume++];
		printf("\n Counsumed : %d",consume);
		pthread_mutex_unlock(&mutex);
		if(produce!=consume+10)
			sem_post(&semaphore);

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