#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
	int fd, n=1, status;
	struct sockaddr_in address;
	char buf[40];

	fd = socket(AF_INET, SOCK_STREAM, 0);
	//if(fd==-1)
		//printf("\n Error");
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(10200);

	status = connect(fd,(struct sockaddr *)&address, sizeof(address));
	if(status==-1)
		printf("\n Error");

	printf("\n Enter a reference string : ");
	gets(buf);
	n=write(fd,buf,strlen(buf));
	while(n)
	{
		n=read(fd,buf,sizeof(buf));
	}
	printf("\n The String returned is : %s",buf);	
}