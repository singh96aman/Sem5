//
//  main.c
//  quicksort
//
//  Created by Aman Singh Thakur on 03/11/17.
//  Copyright © 2017 Aman Singh Thakur. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int n=6;
void swap(int a[n], int i, int j)
{
    int temp = a[i];
    a[i]=a[j];
    a[j]=temp;
}

int partition(int arr[n], int l, int r)
{
    int v=arr[l];
    int i=l, j=r+1;
    while(i<=j)
    {
        while(arr[++i]<=v);
        while(arr[--j]>v);
        swap(arr,i,j);
    }
    swap(arr,i,j);
    swap(arr,l,j);
    return j;
}

void quicksort(int a[n], int l, int r)
{
    if(l<r)
    {
        int p=partition(a,l,r);
        quicksort(a,l,p-1);
        quicksort(a,p+1,r);
    }
}

int main()
{
    int arr[]={5,3,6,1,2,4};
    int n=6;
    quicksort(arr,0,5);
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);
}
