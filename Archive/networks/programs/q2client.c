#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
#include<error.h>

int main()
{
	char buf[1024],buff[1024];
	struct sockaddr_in address;
	int len=sizeof(address);
	int sd=socket(AF_INET,SOCK_STREAM,0);
	address.sin_family=AF_INET;
	address.sin_addr.s_addr=inet_addr("127.0.0.1");
	address.sin_port=htons(4099);
	int result=connect(sd,(struct sockaddr *)&address,len);
	if(result==-1)
	{
		perror("Client error");
		exit(1);
	}
	printf("Enter the name of the file\n");
	scanf("%s",buf);
	int nbytes=write(sd,buf,sizeof(buf));
	
	while(1)
	{
		nbytes=read(sd,buff,1000);
		if(x<0) perror("sds: ");
		if(nbytes==0) break;
		printf("%d\n",nbytes);
		printf("%s\n",buff);
	}
	return 0;
}
	
