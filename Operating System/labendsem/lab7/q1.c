#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
	int fd[2];
	pid_t cpid;
	char buf[30];
	int n=5;
	if(pipe(fd)==-1){printf("\nerror");}
	cpid=fork();
	if(cpid==0){
		while(read(fd[0],&buf,30)>0)
			printf("\n%s\n",buf);
		close(fd[0]);
	}else{
		close(fd[0]);
		char arr[40];
		gets(arr);
		write(fd[1],arr,strlen(arr));
		close(fd[1]);
	}
}