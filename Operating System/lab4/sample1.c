#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	pid_t pid;
	pid = fork();
	if(pid<0){
		fprintf(stderr,"Fork Failed");
		exit(-1);
	}
	else if(pid==0){
		execl("ques1","ques1",NULL);
	}
	else{
		wait(NULL);
		printf("Child complete");
		exit(0);
	}
}
