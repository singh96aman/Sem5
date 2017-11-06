#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
int main()
{
	int fp=open("newfile.txt",O_RDWR);
	char arr[100];
	//read(fp,arr,sizeof(arr));

	int start=0;
	int middle=strlen(arr)/2;
	int end=strlen(arr)-1;

	int fd=creat("newfile3.txt",444);
	//lseek(fp,start,SEEK_END);
	//lseek(fp,middle,SEEK_END);
	read(fp,arr,(sizeof(char)*2));
	write(fd,arr,(sizeof(char)*2));
}