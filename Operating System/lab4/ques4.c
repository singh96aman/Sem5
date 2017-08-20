#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
void main(){
	pid_t pid;
	pid=fork();
	if(pid<0){
		fprintf(stderr,"Fork Failed");
		exit(-1);
	}
	else if(pid==0){
		sleep(5);
		printf("Child terminated\n");
		exit(0);
	}
	else{
		sleep(10);
		exit(0);
	}
}
