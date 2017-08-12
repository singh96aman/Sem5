#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}*NODE;

NODE insert(NODE root, int d){

	//Base case 
	if(root==NULL)
	{
		NODE newnode = (struct node *) malloc(sizeof(struct node *));
		newnode -> data =d;
		newnode -> left = NULL;
		newnode ->right = NULL;
		return newnode;
	}

	if(root->data > d)
		insert(root->right,d);
	else
		insert(root->left,d);
	return root;
}

void inorder(NODE root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

int main(){
	NODE root;
	root = insert(root, 5);
	root = insert(root, 2);
	root = insert(root, 3);
	root = insert(root, 7);
	root = insert(root, 6);

	inorder(root);
	printf("\n");
}