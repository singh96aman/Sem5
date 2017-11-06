#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int fp=creat("newfile.txt",444);
	char arr[40];
	gets(arr);
	write(fp,arr,strlen(arr));
	close(fp);

	fp=open("newfile.txt",O_RDWR);
	read(fp,arr,sizeof(arr));
	printf("%s",arr);

	int fd=creat("newfile2.txt",444);
	write(fd,arr,strlen(arr));	
}