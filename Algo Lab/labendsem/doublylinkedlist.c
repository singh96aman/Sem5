#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node *rlink;
	struct node *llink;
}*Node;

Node add(Node root, int value)
{
	Node newnode = (struct node *) malloc(sizeof(struct node *));
	newnode->val=value;
	Node temp = root;
	if(root==NULL)
	{
		newnode->llink=NULL;
		newnode->rlink=NULL;
		return newnode;
	}
	while(temp->rlink!=NULL)
		temp=temp->rlink;
	temp->rlink=newnode;
	temp->rlink->llink=temp;
	temp->rlink->rlink=NULL;

	return root;
}

void print(Node root)
{
	Node temp=root;
	while(temp)
	{
		printf("%d  ",temp->val);
		temp=temp->rlink;
	}

	printf("\n");
}

Node delete(Node root, int search)
{
	Node temp = root;
	if(root->val==search)
		root=root->rlink;
	else{
		while(temp->rlink!=NULL)
		{
			//printf("%d\n",temp->val);
			if(search==temp->val)
			{
				/*if(temp->rlink!=NULL)
					temp->rlink->llink- = temp->llink;
				if(temp->llink!=NULL)
					temp->llink->rlink = temp->rlink;*/
				printf("%d\n",temp->llink->val);
			}
			temp=temp->rlink;
		}
		}	
		//print(root);
	return root;
}

int main()
{
	Node root=NULL;
	for(int i=0; i<5; i++)
		root=add(root,i);
	print(root);
	root=delete(root,2);
	print(root);
}