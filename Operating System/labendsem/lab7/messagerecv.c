#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define size 10

struct my_message{
	long int message_type;
	char buf[size];
};

int main()
{
	int msgid;
	struct my_message some_message;
	long int message_to_recv=0;
	char data[40];
	msgid=msgget((key_t)5432,0666|IPC_CREAT);
	while(1)
	{
		if(msgrcv(msgid,(void*)&some_message,size,message_to_recv,0)==-1)
			printf("\n Error");
		printf("\n You wrote %s\n",some_message.buf);
		if(strcmp(some_message.buf,"end")==0)
			break;
	}
	if(msgctl(msgid,IPC_RMID,0)==-1){
		printf("Error");
	}
}