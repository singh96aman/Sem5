#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
int main()
{
  int status;
  pid_t pid;
  int i;
  for(i=0; i<3; i++)
    pid = fork();
  if(pid==-1)
    printf("\n Error creating Child Process\n");
  else if(pid==0){
    //wait(&status);
    printf("\n Inside the Child Process \n");
  }
  else{
    printf("\n Inside the Parent Process\n");
  }
}
