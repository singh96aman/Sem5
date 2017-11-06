#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
		printf("\nError");
	else if(pid==0)
	{
		sleep(5);
		printf("\n Child terminated");
		exit(0);
	}
	else{
		sleep(10);
		exit(0);	}
}