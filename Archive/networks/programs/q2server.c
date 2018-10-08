#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<time.h>
#include<string.h>

int main()
{
	int sd;
	pid_t pid;
	FILE *f;
	char buf[1024],buffer[1024],a[1024],q=1,m=10;
	struct sockaddr_in sadd,cadd;
	sd=socket(AF_INET,SOCK_STREAM,0);
	sadd.sin_family=AF_INET;
	sadd.sin_addr.s_addr=inet_addr("127.0.0.1");
	sadd.sin_port=htons(4099);
	int result=bind(sd,(struct sockaddr *)&sadd,sizeof(sadd)); 
	int len=sizeof(cadd);
	listen(sd,5);
	for(;;)
	{
		int ns=accept(sd,(struct sockaddr *)&cadd,&len);
		if((pid=fork())==0)
		{
			close(sd);
			int p=read(ns,buf,sizeof(buf));
			printf("the file requested %s\n",buf);
			int n=open(buf,O_RDONLY,0777);
			if(n==-1)
			{
				strcpy(buffer,"File not found");
				q=write(ns,buffer,sizeof(buffer));
			}
			else
			{
				while (m!=0)
				{
					m=read(n,buffer,1000);
					if(m<0) perror("sds: ");
					q=write(ns,buffer,sizeof(buffer));
					printf("bytes sent = %d\n",m);
				}
				printf("file sent\n");
			}
			close(ns);
			exit(0);
		}
		close(ns);
	}
	return 0;
}
