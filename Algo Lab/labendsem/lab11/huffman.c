#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char data;
	float freq;
	struct node *lchild, *rchild;
	int code;
}*Node;

Node buildnode(char data, float freq)
{
	Node newnode = (struct node *) malloc(sizeof(struct node));
	newnode->data=data;
	newnode->freq=freq;
	newnode->lchild=NULL;
	newnode->rchild=NULL;
	newnode->code=-1;
	return newnode;
}

Node buildbignode(Node left, Node right)
{
	Node newnode = (struct node *) malloc(sizeof(struct node));
	newnode->data=' ';
	newnode->freq=left->freq+right->freq;
	left->code=0;
	right->code=1;
	newnode->code=-1;
	newnode->lchild=left;
	newnode->rchild=right;
	return newnode;
}

void printLeaves(Node root)
{
	if(root->code!=-1)
		printf("%f   %d\n",root->freq,root->code);
	if(root->data!=' ')
		printf("%c\n",root->data);

	if(root->lchild!=NULL && root->rchild!=NULL)
	{
		printLeaves(root->rchild);
		printLeaves(root->lchild);
	}
}

int main()
{
	int n=3;
	Node root[n];
	for(int i=0; i<n; i++)
	{
		char c; float f;
		scanf("%c %f",&c,&f);
		root[i]=buildnode(c,f);
	}
	while(n)
	{
		for(int i=0; i<n-1; i++)
			for(int j=0; j<n-1; j++)
				if(root[j]->freq > root[j+1]->freq)
				{
					Node temp=root[j];
					root[j]=root[j+1];
					root[j+1]=temp;
				}
			Node sumnode=buildbignode(root[0],root[1]);
			root[0]=sumnode;
			for(int j=1; j<n; j++)
				sumnode[j]=sumnode[j+1];
		n--;
	}
	printLeaves(root[0]);
}