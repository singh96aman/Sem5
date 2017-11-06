#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void func()
{
	int status;
	int pid=fork();
	if(pid==-1)
		printf("\n Error!");
	else if(pid==0)
	{
		printf("\n");
		//execlp("/bin/ls","ls",NULL);
		execl("helloworld","helloworld",NULL);
		//execlp("wc","wc","-l","q1.c",(char*)0);
		//execlp("grep","-I","-n","main","q1.c",(char*)0);
	}else
		printf("\n Inside of parent of second program!");
}

int main()
{
	func();
}
