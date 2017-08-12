#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<time.h>
#define PORTNO 10999
int main(){

	int sockfd, newsockfd, portno, clilen, n=1;
	char buf[256],pids[5];

	struct sockaddr_in seraddr, cliaddr;
	int i, value;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(PORTNO);
	bind(sockfd,(struct sockaddr *)&seraddr, sizeof(seraddr));
	listen(sockfd,1);
	clilen = sizeof(clilen);
	while(1){
		newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);
		if(fork()==0){
			time_t t;
			time(&t);
			asctime_r(localtime(&t),buf);
			n=write(newsockfd,buf,sizeof(buf));
			int pid=getpid();
			snprintf(pids,10,"%d",pid);
			n=write(newsockfd,pids,sizeof(pids));
		}
	}
	return 0;
}
