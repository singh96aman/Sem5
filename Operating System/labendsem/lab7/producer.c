#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#define size 10

struct shared{
	char buf[40];
	int writtenbyme;
};

int main()
{
	void *shared_memory = (char*)0;
	struct shared *shared_stuff;
	char buf[size];
	int shmid;
	shmid=shmget((key_t)1234,sizeof(struct shared *), 0666|IPC_CREAT);
	shared_memory=shmat(shmid,(void*)0,0);
	shared_stuff=(struct shared *)shared_memory;
	shared_stuff->writtenbyme=0;
	while(1)
	{
		printf("\n Enter Value :");
		gets(buf); 
		//printf("\n %s\n",buf);
		strcpy(shared_stuff->buf,buf);
		shared_stuff->writtenbyme=1;
		if(strcmp(shared_stuff->buf,"end")==0)
			break;
		if(shmdt(shared_memory)==-1)
			printf("\n Failed");
	}
}