#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
void main(){
	int fp = creat("newfile.txt",444);
	char arr[256];
	gets(arr);
	write(fp,arr,strlen(arr));
	close(fp);
}
