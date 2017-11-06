#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
//char buf[]="HELLO\0";
int buf[4];
int main(){
	int fd;
	char *myfifo="new2";
	fd=open(myfifo,O_RDWR);
	printf("%d\n",fd);
	read(fd,buf,sizeof(int)*4);
	for(int i=0;i<5;i++){
		printf("%d",buf[i]);
	}
	//res=write(fd,buf,sizeof(buf));
	close(fd);
	return 0;
}