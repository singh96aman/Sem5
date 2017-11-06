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
		printf("\nInside Child Processs");
		printf("\nChild Id : %d",getpid());
		printf("\nParent Id : %d",getppid());
	}
	else
	{
		wait(&status);
		printf("\n This is the parent !\n");
		printf("\nChild Id : %d",getpid());
		printf("\nParent Id : %d",getppid());
	}
}

int main()
{
	func();
}