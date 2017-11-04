#include <stdio.h>
#include <stdlib.h>
#define Size 7
typedef struct node
{
	int val;
	struct node *link;
}*Node;

int main()
{
	int size=5;
	Node a[size];
	int n=6;
	int arr[]={45,12,67,35,23,24};
	for(int i=0; i<size; i++)
		a[i]=NULL;
	for(int i=0; i<n; i++)
	{
		int index=arr[i]%size;
		if(a[index]==NULL)
		{
			Node temp = (struct node *) malloc(sizeof(struct node));
			temp->val=arr[i];
			temp->link=NULL;
			a[i]=temp;
		}
		else
		{
			Node newnode = (struct node *) malloc(sizeof(struct node));
			newnode->val=arr[i];
			newnode->link=NULL;
			Node temp=a[index];
			while(temp->link!=NULL)
				temp=temp->link;
			temp->link=newnode;
		}
	}
	for(int i=0; i<n; i++)
	{
		Node temp = a[i];
		while(temp)
		{
			printf("Key : %d , Value : %d\t",i,temp->val);
			temp=temp->link;
		}
		printf("\n");
	}
}