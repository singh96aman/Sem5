
#include <stdlib.h>
#include <stdio.h>
int n=4;
int pop[20];
int pop_i=0;
void dfs(int arr[n][n], int v, int visited[n])
{
    int j=0;
    visited[v]=1;
    printf("%d\n",v);
    for(j=0; j<n; j++){
        //printf("%d %d   ",j, visited[j]);
        if(!visited[j] && arr[v][j]!=0)
        {
        visited[j]=1;
        dfs(arr,j,visited);
        pop[pop_i]=j;
        printf("%d",j);
        pop_i++;
        j++;
        }
    }
    printf("\n");
}

int main()
{
    int arr[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d",&(arr[i][j]));
    
    int visited[n];
    for(int i=0; i<n; i++)
        visited[i]=0;
    
    for(int i=0; i<n; i++)
    {
        if(visited[i]==0)
        {
            visited[i]=1;
            dfs(arr,i,visited);
            pop[pop_i]=i;
            pop_i++;
            //i++;
        }
    }
    printf("\n");
    for(int i=0; i<n; i++)
        printf("%d",pop[i]+1);
    
}