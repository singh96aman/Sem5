#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}*Node;

Node create(Node root,int n)
{
	Node newnode = (struct  node *) malloc(sizeof(struct node));
	newnode->data=n;
	newnode->right=NULL;
	newnode->left=NULL;
	if(root==NULL)
		return newnode;
	Node parent=NULL, temp =root;
	while(temp)
	{
		parent=temp;
		if(temp->data > n)
			temp = temp->left;
		else
			temp = temp->right;
	}
	if(parent->data > n)
		parent->left = newnode;
	else
		parent->right = newnode;
	return root;
}

int count(Node root, int c)
{
	if(root)
	{
		c=1+count(root->left,c)+count(root->right,c);
	}
	return c;
}

int main()
{
	Node root=NULL;
	root=create(root,4);
	root=create(root,7);
	root=create(root,8);
	root=create(root,9);
	root=create(root,4);
	root=create(root,5);
	root=create(root,2);
	printf("%d ",count(root,0));
}