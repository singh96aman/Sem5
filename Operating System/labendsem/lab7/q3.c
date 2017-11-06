#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <string.h>
struct shared{
	char c;
};

int main()
{
	pid_t pid;
	int status;
	void *sm = (void*)0;
	struct shared *s;
	int shmid=shmget((key_t)1234, sizeof(struct shared *), 0666 | IPC_CREAT);
	sm = shmat(shmid,(void*)0,0);
	s = (struct shared * )sm;
	char q;
	scanf("%c",&q);
	s->c=q;
	pid=fork();
	if(pid==0)
	{
		(s->c)++;
	}
	else
	{
		wait(&status);
		printf("\n%c\n",s->c);
	}

}