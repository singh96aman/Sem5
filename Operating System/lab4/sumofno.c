#include<stdio.h>

int findSum(int num1[100], int num2[100], int sum[100], int len1, int len2)
{
  int i = 0, j = 0, k=0, carry=0;
  for(; i<len1 || j<len2; i++,j++,k++)
  {
    //printf("\n%d",carry);
    sum[k]=(num1[i]+num2[j]+carry)%10;
    carry=(num1[i]+num2[j]+carry)/10;
  }
  if(carry!=0)
    sum[k++]=carry;
  return k;
}

int main()
{
  int num1[100] = {2,1,8,9,2,2,9,9,5,8,3,4,5,5,5,1,6,9,0,2,6};
  int num2[100] = {7,5,4,0,1,1,3,8,0,4,7,4,6,3,4,6,4,2,9};
  int len1=20, len2=18;
  int sum[100];
  int len3 = findSum(num1, num2, sum, len1, len2);
  for(int i=len1-1; i>=0; i--)
    printf("%d",num1[i]);
  printf("\n");
  for(int i=len2-1; i>=0; i--)
    printf("%d",num2[i]);
  printf("\n%d\n",len3);
  for(int i=len3-1; i>=0; i--)
    printf("%d",sum[i]);

}
