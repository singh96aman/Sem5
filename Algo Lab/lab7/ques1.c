#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node *left;
	struct node *right;
	int height;
}*Node;

int height(Node root)
{
	if(!root)
		return 0;
	return 1+max(height(root->left),height(root->right));
}

int getbalance(Node root)
{
	return height(root->left) - height(root->right);
}

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

Node rightRotate(Node root)
{
	Node y=root;
	Node x=root->left;

	Node T1=x->left;
	Node T2=x->right;
	Node T3=y->right;

	Node newroot=x;
	x->left=T1;
	x->right=y;
	y->left=T2;
	y->right=T3;

	x->height = height(x);
	y->height = height(y);

	return newroot;
}

Node leftRotate(Node root)
{
	Node x=root;
	Node y=root->right;

	Node T1=x->left;
	Node T2=y->left;
	Node T3=y->right;

	Node newroot=y;
	y->right=T3;
	y->left=x;
	x->left=T1;
	x->right=T2;

	y->height = height(y);
	x->height = height(x);

	return newroot;
}

void inorder(Node root)
{
	if(!root)
		return;
	inorder(root->left);
	printf("%d ",root->val);
	inorder(root->right);
}

Node createnewNode(int key)
{
	Node newnode = (struct node *) malloc(sizeof(struct node));
	newnode->val=key;
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->height=0;
	return newnode;
}

Node createAVL(Node root, int key)
{

	if(!root)
		return createnewNode(key);

	if(key>root->val)
		root->right = createAVL(root->right,key);
	else
		root->left = createAVL(root->left,key);
	
	//inorder(root);	

	root->height = height(root);
	
	int bal = getbalance(root);

	//Left Left Case
	if(bal>1 && key < root->left->val)
		return rightRotate(root);
	//Left Right Case
	else if(bal>1 && key > root->left->val)
	{
		root=leftRotate(root);
		return rightRotate(root);
	}
	//Right Left Case
	else if(bal<-1 && key < root->right->val)
	{
		root=rightRotate(root);
		return leftRotate(root);
	}
	//Right Right Case
	else if(bal<-1 && key > root->right->val)
		return leftRotate(root);
		

	return root;
}

int main()
{
	printf("\n Creating AVL Trees !\n");
	
	 int val=0;
	 Node root=NULL;
	// /*
	// while(1)
	// {
	// 	if(val==-1)
	// 		break;
	// 	printf("\n Enter Value : ");
	// 	scanf("%d",&val);
	// 	root=createAVL(root,val);
	// 	inorder(root);
	// 	printf("\n");
	// }
	// inorder(root);
	// */
	
	// Node root=NULL;
	 root=createAVL(root,10);
	//inorder(root);
	// printf("Hello");
	root=createAVL(root,5);
	// printf("Hello");
	root=createAVL(root,1);
	 root=createAVL(root,20);
	 root=createAVL(root,2);
	 root=createAVL(root,3);
	 root=createAVL(root,4);
	 root=createAVL(root,6);
	inorder(root);
}