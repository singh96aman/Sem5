#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/shm.h>

struct shared{
	char buf[40];
	int writtenbyme;
};

int main()
{
	void *shared_memory = (void*)0;
	struct shared *shared_stuff;
	int shmid = shmget((key_t)1234,sizeof(struct shared *),0666|IPC_CREAT);
	shared_memory=shmat(shmid,(void*)0,0);
	shared_stuff=(struct shared *) shared_memory;
	shared_stuff->writtenbyme=0;
	while(1)
	{
		if(shared_stuff->writtenbyme)
		{
			printf("\n You wrote : %s\n",shared_stuff->buf);
			shared_stuff->writtenbyme=0;
			//sleep(rand()%4);
		}
		if(strcmp(shared_stuff->buf,"end")==0)
			break;
	}
}