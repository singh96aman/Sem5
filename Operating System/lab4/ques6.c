#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
void main(){
	
	int fp=open("newfile.txt",O_RDONLY);
	char buffer[256];
	int fg=creat("newfile2.txt",444);
	read(fp,buffer,sizeof(buffer));
	write(fg,buffer,strlen(buffer));
	close(fp);
	close(fg);

}
