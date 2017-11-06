#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void func()
{
	int status;
	int pid=fork();
	if(pid==-1)
		printf("\n Error");
	else if(pid==0) //child process
	{
		for(int i=0; i<10; i++)
			printf("\n This is child!");
	}
	else
	{
		wait(&status);
		printf("\n This is the parent !\n");
	}
}

int main()
{
	func();
}