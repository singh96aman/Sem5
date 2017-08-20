#include<sys/types.h>
#include<sys/wait.h>
void main(){
	int status;
	pid_t pid;
	pid = fork();
	printf("\nParent process running");
	if(pid==-1)
		printf("\nError child not created");
	else if(pid==0){
	printf("\n Child process running");
	exit(0);
	}
	else{
	wait(&status);
	printf("\n Wait invoked");
	printf("\n Parent entered!");
	printf("\n Child returned : %d\n",status);
	}
}
