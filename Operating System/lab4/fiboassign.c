#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

int findSum(int num1[100], int num2[100], int sum[100], int len1, int len2)
{
  int i = 0, j = 0, k=0, carry=0;
  for(; i<len1 || j<len2; i++,j++,k++)
  {
    sum[k]=(num1[i]+num2[j]+carry)%10;
    carry=(num1[i]+num2[j]+carry)/10;
  }
  if(carry!=0)
    sum[k++]=carry;
  return k;
}

int copyArray(int first[100], int second[100], int len2)
{
  for(int i=0; i<len2; i++)
  {
    first[i]=second[i];
  }
  return len2;
}

void *child_thread()
{
  printf("\n Inside Different Thread !");
  int num1[100] = {0};
  int num2[100] = {1};
  int sum[100];
  int len1=1, len2=1, len3, k=1;
  int sum_total[100]={0};

  for(int i=3; i<=100; i++)
  {
    len3 = findSum(num1,num2,sum,len1,len2);
    int total[100];
    k = findSum(sum_total,sum,total,k,len3);
    copyArray(sum_total,total,k);
    len1=copyArray(num1,num2,len2);
    len2=copyArray(num2,sum,len3);
    //printf("\n%d",k);
  }
  printf("\n The Sum is : \n");
  for(int i=k-1; i>=0; i--)
    printf("%d",sum_total[i]);
}

int main()
{
  pthread_t thread;
  pthread_create(&thread,0,&child_thread,0);
  printf("\n In Main Thread");
  pthread_join(thread,0);
}
