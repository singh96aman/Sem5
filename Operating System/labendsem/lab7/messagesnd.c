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

#define size 10


struct my_message{
	long int message_type;
	char buf[size];
};

int main()
{
	struct my_message some_message;
	int msgid;
	char data[size];
	msgid=msgget((key_t)5432,0666|IPC_CREAT);
	while(1)
	{
		printf("\n Enter some text :");
		gets(data);
		some_message.message_type=1;
		strcpy(some_message.buf,data);
		if(msgsnd(msgid,(void*)&some_message,10,0)==-1)
			printf("\n Error");
		if(strcmp(data,"end")==0)
			break;
	}
}