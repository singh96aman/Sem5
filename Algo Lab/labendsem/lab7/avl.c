#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
	int height;
}*Node;

int max(int a, int b)
{
	return a>b ? a:b;
}

int height(Node root)
{
	if(root==NULL)
		return 0;
	else
		return 1 + max(height(root->left),height(root->right));
}

int getbalance(Node root)
{
	return height(root->left)-height(root->right);
}

Node rightRotate(Node y)
{
	Node x=y->left;
	Node T2=x->right;

	x->right=y;       
	y->left=T2;

	y->height=max(height(y->left),height(y->right))+1;
	x->height=max(height(x->left),height(x->right))+1;
	return x;
}

Node leftRotate(Node y)
{
	Node x=y->right;
	Node T2=x->left;

	y->left=x;
	x->right=T2;
	
	y->height=max(height(y->left),height(y->right))+1;
	x->height=max(height(x->left),height(x->right))+1;
	return y;
}

Node createAVLTree(Node root, int n)
{
	if(root==NULL)
	{
		Node newnode = (struct node *) malloc(sizeof(struct node));
		newnode->data=n;
		newnode->left=NULL;
		newnode->right=NULL;
		newnode->height=0;
		return newnode;
	}
	if(n > root->data)
		root->right = createAVLTree(root->right, n);
	else
		root->left = createAVLTree(root->left, n);

	root->height=height(root);
	int bal=getbalance(root);

	if(bal > 1 && n < root->left->data) // Left Left
		return rightRotate(root);
	else if (bal >1 && n > root->left->data) // Left Right Case
	{
		root=leftRotate(root);
		return rightRotate(root);
	}
	else if (bal < -1 && n < root->right->data) // Right Left
	{
		root=rightRotate(root);
		return leftRotate(root);
	}
	else
	{
		return rightRotate(root);
	}
}

void inorder(Node root)
{
	if(!root)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

int main()
{
	Node root=NULL;
	int val=0;
	while(1)
	{
		if(val==-1)
			break;
		printf("\n Enter Value : ");
		scanf("%d",&val);
		root=createAVLTree(root,val);
	}
	inorder(root);
}