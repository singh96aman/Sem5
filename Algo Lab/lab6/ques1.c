#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *right;
	struct node *left;
}*Node;

Node create(){
    struct  node *root = (struct node *)malloc(sizeof(struct node));
    printf("Enter data(-1 for no data)");
    int x;
    scanf("%d",&x);
    if(x==-1){
      return NULL;
    }
    root->data=x;
    printf("\nEnter left child of %d\n",x);
    root->left = create();
     printf("\nEnter right child of %d\n",x);
    root->right = create();
    return root;
}

	int opcount=0;

int count(Node root, int c)
{
	opcount++; // comparision of root to NULL
	if(root)
	{
		c = count(root->left,c) + count(root->right,c)+ 1;
	}
	return c;
}

int main()
{
	Node root = NULL;
	root = create();
	printf("\nNo Of Nodes is %d\n",count(root,0));
	printf("\n No Of Operations is : %d",opcount); 
}