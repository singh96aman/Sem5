#include <stdio.h>
#include <stdlib.h>

void main()
{
  printf("Enter the number of vertices\n");
  int vertices;
  scanf("%d",&vertices);
  int arr[vertices][vertices];
  int queue[1000];
  for(int i=0;i<=999;i+=1)
    queue[i]=0;
  int f=-1,r=-1;
  for(int i=0;i<vertices;i+=1)
  {
    for(int j=0;j<vertices;j+=1)
    {
      scanf("%d",&arr[i][j]);
    }
  }

  r+=1;
  queue[r]=0;
  int visited[vertices];
  for(int i=0;i<vertices;i+=1)
    visited[i]=0;
  visited[0]=1;
  printf("Traversal Order :\n");
  while(f<=r)
  {
    f++;
    if(f>r)
      break;
    int a=queue[f];
    printf("%d ",a+1);
    for(int j=0;j<vertices;j+=1)
    {
      if(visited[j]!=1 && arr[a][j]==1)
      {
        r+=1;
        queue[r]=j;
        visited[j]=1;
      }
    }
  }
}
