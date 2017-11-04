/*#include <stdlib.h>
#include <stdio.h>

int c=0;
int arr[100][100];
int min=10000;
char answer[100];
int size=0;
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
   {
     int sum=0;
     for(int i=0;i<size;i+=1)
     {
       int n1=a[i]-48;
       sum+=arr[i][n1];
     }
     if(sum<min)
     {
       min=sum;
       strcpy(answer,a);
     }
}
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i));
       }
   }
}
int main()
{
    printf("Enter the size\n");
    scanf("%d",&size);
    for(int i=0;i<=size-1;i+=1)
    {
      for(int j=0;j<=size-1;j+=1)
      {
        scanf("%d",&arr[i][j]);
      }
    }
    char str[100];
    for(int i=0;i<size;i+=1)
    {
      str[i]=(i+48);
    }
    int n = strlen(str);
    permute(str, 0, n-1);
      printf("%d is the minimum cost\n",min);//minimum cost
    for(int i=0;i<size;i+=1)
    {
      printf("%d gets job  %c\n",i+1,answer[i] + 1);
    }
    return 0;
}
*/


#include <stdio.h>
#include <stdlib.h>

//permute
//swap
int n=4;
int min=99999;
char *answer;

void swap(char *a, char *b)
{
	char temp=*a;
	*a=*b;
	*b=temp;
}

void permute(int arr[n][n],char *a, int l, int r)
{
	if(l==r)
	{
		//printf("%s",a);
		int sum=0;
		for(int i=0; i<n; i++)
		{
			int n1 = a[i]-48;
			sum+=arr[i][n1];
		}
		//printf("%d\n",sum);
		if(sum<min)
		{
			min=sum;
			strcpy(answer,a);
		}
	}
	else
	{
		for(int i=l; i<=r; i++)
		{
			swap((a+l),(a+i));
			permute(arr,a,l+1,r);
			swap((a+l),(a+i));
		}	
	}
}

int main()
{
	int n=4;
	int arr[n][n];
	answer = (char *) malloc(100*sizeof(char));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d",&(arr[i][j]));
	char a[n];
	for(int i=0; i<n; i++)
		a[i]=i+48;
	permute(arr,a,0,n-1);
	printf("%d",min);
	for(int i=0; i<n; i++)
		printf("\n %d gets job %d\n",i+1,arr[i][answer[i]-48]);
}