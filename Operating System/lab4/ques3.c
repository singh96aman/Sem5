#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
void main(){
	int status;
	pid_t pid;
	pid = fork();
	if(pid==-1)
		printf("\nError child not created");
	else if(pid==0){
	printf("Inside Child\n");
	printf("%d is Parent id\n",getppid());
	printf("%d is Child id\n",getpid());
	printf("%d is process id\n",pid);
	exit(0);
	}
	else{
	printf("Inside Parent\n");
	//printf("%d is Parent id\n",getppid());
	printf("%d is Child id\n",getpid());
	printf("%d is process id\n",pid);
	}	
}
