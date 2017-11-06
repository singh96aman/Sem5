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
		//for(int i=0; i<10; i++)
		//	printf("\n This is child!");
		printf("\nInside Child Processs");
		printf("\nChild Id : %d",getpid());
		printf("\nParent Id : %d",getppid());
		sleep(5);
		printf("\nInside Child Processs2222");
		printf("\nChild Id : %d",getpid());
		printf("\nParent Id : %d",getppid());
	}
	else
	{
		sleep(2);
		printf("\nInside Parent Processs");
		printf("\nChild Id : %d",getpid());
		printf("\nParent Id : %d",getppid());
		exit(0);
	}
}

int main()
{
	func();
}