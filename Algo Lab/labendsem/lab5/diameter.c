// BINARY TREE USED !!!


#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}*Node;

Node create()
{
	struct node *root = (struct node *) malloc(sizeof(struct node));
	int x;
	scanf("%d",&x);
	if(x==-1)
		return NULL;
	root->data=x;
	printf("\n Enter left child of %d",x);
	root->left=create();
	printf("\n Enter right child of %d",x);
	root->right=create();
	return root;
}

int max(int a, int b)
{
	return a>b ? a : b;
}

int height(Node root)
{
	if(root==NULL)
		return -1;
	else 
		return 1+max(height(root->left),height(root->right));
}

int diameter(Node root)
{
	if(root==NULL)
		return 0;
	int lheight=height(root->left);
	int rheight=height(root->right);
	int ldiamter=diameter(root->left);
	int rdiameter=diameter(root->right);
	return max(1+lheight+rheight,max(ldiamter,rdiameter));
}

int main()
{
	Node root=NULL;
	root=create();
	printf("\n%d",diameter(root));
}