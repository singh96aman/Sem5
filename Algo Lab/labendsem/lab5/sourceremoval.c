
#include <stdlib.h>
#include <stdio.h>
int v=4;
void source_removal(int arr[v][v])
{
    int no[v];
    for(int i=0; i<v; i++)
        no[i]=0;
    for(int i=0; i<v; i++)
    {	int count=0;
        for(int j=0; j<v; j++)
            if(arr[i][j]==1)
                count++;
        no[i]=count;
    }
    //for(int i=0; i<v; i++)
      //  printf("%d ",no[i]);
    int c=0;
    while(c<v)
    {
        for(int i=0; i<v; i++)
        {
            if(no[i]==-1)
                continue;
            if(no[i]==0)
            {
                no[i]=-1;
                   c++;
                printf("%d\n",i);
                for(int j=0; j<v; j++)
                    if(arr[j][i]==1)
                    {
                    	//printf("%d %d\n",i,j);
                        arr[j][i]=0;
                        no[j]--;
                    }
            }
        }
    }
}

int main()
{
    int a[v][v];
    for(int i=0; i<v; i++)
        for(int j=0; j<v; j++)
            scanf("%d",&(a[i][j]));
    source_removal(a);
}