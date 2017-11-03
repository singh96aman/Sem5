#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>

int main()
{
	int clilen, n=1, sockfd, newsockfd;
	struct sockaddr_in seraddr, cliaddr;
	char buf[256];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = INADDR_ANY;
	seraddr.sin_port = htons(10200);

	bind(sockfd,(struct sockaddr *)&seraddr, sizeof(seraddr));
	listen(sockfd,1);
	clilen = sizeof(clilen);
	newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr	, &clilen);
	printf("\n Hello");
	//read(newsockfd, buf, sizeof(buf));
	time_t t;
	time(&t);
	asctime_r(localtime(&t),buf);
	printf("\n %s",buf);
	write(newsockfd, buf, strlen(buf));
}