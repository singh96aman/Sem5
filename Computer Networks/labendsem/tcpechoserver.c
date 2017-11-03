#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#define PORTNO 10200

int main()
{
	int sockfd, newsockfd, n=1, status, clilen;
	struct sockaddr_in seraddr, cliaddr;
	char buf[40];	
	
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	//if(sockfd==-1)
		//printf("\n Error");
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = INADDR_ANY;
	seraddr.sin_port = htons(PORTNO);

	bind(sockfd,(struct sockaddr *)&seraddr, sizeof(seraddr));
	//if(status==-1)
		//printf("\n Error");
	listen(sockfd,1);
	clilen = sizeof(clilen);
	newsockfd = accept(sockfd,(struct sockaddr *)&cliaddr, &clilen);
	//if(newsockfd==-1)
		//printf("\n Error");

	n = read(newsockfd,buf,sizeof(buf));
	printf("\n Message from client : %s",buf);
	gets(buf);
	n = write(newsockfd,buf,sizeof(buf));
}