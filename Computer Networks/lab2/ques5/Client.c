#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
int main()
{
int len,result,sockfd,n=0,m=0;
struct sockaddr_in address;

sockfd = socket(AF_INET, SOCK_STREAM, 0);
address.sin_family=AF_INET;
address.sin_addr.s_addr=inet_addr("127.0.0.1");
address.sin_port=htons(11130);
len = sizeof(address);
result=connect(sockfd,(struct sockaddr *)&address,len);
if(result==-1){
perror("\nCLIENT ERROR");
exit(1);
}
char sentence[100];
printf("Please Enter The Sentence : ");
gets(sentence);
send(sockfd,sentence,100,0);
char word[100];
printf("Please Enter The Word : ");
gets(word);
send(sockfd,word,100,0);
char replacer[100];
printf("Please Enter The Replacing Word : ");
gets(replacer);
send(sockfd,replacer,100,0);
char newsentence[100];
recv(sockfd,newsentence,100,0);
printf("Please Enter The New Sentence : %s\n",newsentence);


return 0;
}
