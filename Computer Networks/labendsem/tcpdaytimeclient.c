#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
	struct sockaddr_in address;
	int n=1, sockfd, status;
	char buf[256];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(10200);

	//printf("\n Request for Date and Time ");
	//gets(buf);
	//write(sockfd, buf, sizeof(buf));
	status = connect(sockfd,(struct sockaddr*)&address, sizeof(address));
	printf("\n Hello");
	while(n)
		n=read(sockfd, buf, sizeof(buf));
	printf("\n The current date and time is : %s\n",buf);
}