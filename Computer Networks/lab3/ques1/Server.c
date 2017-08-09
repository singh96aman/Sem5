#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<dirent.h>
#define PORTNO 10677
int main(){
	int sockfd, newsockfd, portno, clilen, n=1;
	char *buf;
	int errno;
	struct sockaddr_in seraddr, cliaddr;
	int i, value;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	seraddr.sin_family=AF_INET;
	seraddr.sin_addr.s_addr=INADDR_ANY;
	seraddr.sin_port=htons(PORTNO);
	bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
	listen(sockfd,1);
	clilen=sizeof(clilen);
	while(1){
		newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);
		if(fork()==0){
			n=read(newsockfd,buf,sizeof(buf));
			printf("\n Message from client %s\n",buf);
			n=write(newsockfd,buf,sizeof(buf));
			DIR *dirp = opendir(".");
			struct dirent *dp;
			while (dirp) {
    				errno = 0;
    			if ((dp = readdir(dirp)) != NULL) {
    				printf("%s\n",dp->d_name);
    				//n=write(newsockfd,dp->d_name,sizeof(dp->d_name));
      			  if (strcmp(dp->d_name, buf) == 0) {
            		closedir(dirp);
            		printf("Found");
       			 }
    			} else {
     			   if (errno == 0) {
        	  	  closedir(dirp);
       			   printf("Not Found");
        		}
       			 closedir(dirp);
       			 printf("Read Error");
   			 }
		}
		printf("Open Error");

	}
}
	return 0;
}
