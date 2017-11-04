//
//  main.c
//  tree2
//
//  Created by Aman Singh Thakur on 03/11/17.
//  Copyright © 2017 Aman Singh Thakur. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *right;
    struct node *left;
}*Node;

Node add(Node root, int n)
{
    //printf("\n hello");
    Node temp=root, parent=NULL;
    Node newnode = (struct node *) malloc(sizeof(struct node ));
    newnode->right=NULL;
    newnode->left=NULL;
    newnode->val=n;
    if(root==NULL)
    {
        root=newnode;
        return root;
    }
    while(temp)
    {
        parent=temp;
        if(temp->val < n)
            temp=temp->right;
        else
            temp=temp->left;
    }
    if(parent->val > n)
        parent->left = newnode;
    else
        parent->right = newnode;
    return root;
}

void inorder(Node root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("\n %d",root->val);
        inorder(root->right);
    }
}

int main()
{
    Node root=NULL;
    for(int j=10; j>=0; j--)
    root=add(root,j);
    inorder(root);
}