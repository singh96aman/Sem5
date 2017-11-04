//
//  main.c
//  dfsmatrix
//
//  Created by Aman Singh Thakur on 03/11/17.
//  Copyright © 2017 Aman Singh Thakur. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
int n=4;
int push[20], pop[20];
int push_i=0, pop_i=0;
void dfs(int arr[n][n], int v, int visited[n])
{
    int j=0;
    visited[v]=1;
    for(j=0; j<n; j++){
        if(!visited[j] && arr[v][j]!=0)
        {
        visited[j]=1;
        push[push_i]=j;
        push_i++;
        dfs(arr,j,visited);
        pop[pop_i]=j;
        pop_i++;
        j++;
        }
    }
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
            push[push_i]=i;
            push_i++;
            dfs(arr,i,visited);
            pop[pop_i]=i;
            pop_i++;
            //i++;
        }
    }
    printf("\n Push order");
    for(int i=0; i<n; i++)
        printf("%d ",push[i]);
    printf("\n");
    for(int i=0; i<n; i++)
        printf("%d",pop[i]);
    
}