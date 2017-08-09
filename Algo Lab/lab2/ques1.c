#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}*NODE;

NODE insert(NODE root, int d){
	NODE temp = root, prev = root;
	while(temp!=NULL){
		prev = temp;
		if(temp->data > d)
			temp = temp -> left;
		else
			temp = temp ->right;
	}
	NODE newnode = (struct node *) malloc(sizeof(struct node *));
	newnode -> data =d;
	newnode -> left = NULL;
	newnode ->right = NULL;
	if(prev==NULL)
		return newnode;
	else{
	if(prev->data > d)
		prev->left = newnode;
	else
		prev ->right = newnode;
	return root;
	}
}

NODE findKey(NODE root, int key){
	NODE temp = root, prev = root;
	int flag=0;
	while(temp!=NULL){
		prev = temp;
		if(temp ->data == key)
			{flag=1; break;}
		if(temp->data > key)
			temp = temp -> left;
		else
			temp = temp ->right;
	}
	if(flag==1)
		{printf("Key Found!"); return root; }
	else
		{ 
	NODE newnode = (struct node *) malloc(sizeof(struct node *));
	newnode -> data =key;
	newnode -> left = NULL;
	newnode -> right = NULL; 
	if(prev -> data > key)
		prev ->left = newnode;
	else
		prev ->right = newnode;
	}
	return root;
}

void inorder(NODE root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void preorder(NODE root){
	if(root!=NULL){
		printf("%d ",root->data);
		inorder(root->left);
		inorder(root->right);
	}
}
void postorder(NODE root){
	if(root!=NULL){
		inorder(root->left);
		inorder(root->right);
		printf("%d ",root->data);
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
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	root = findKey(root, 3);
	printf("\n");
	root = findKey(root, 8);
	printf("\n");
	inorder(root);
}
