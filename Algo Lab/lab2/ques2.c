#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}*NODE;

typedef struct graph{
	int v;
	struct node *AdjList;
}*Graph;

Graph createGraph(Graph g, int n){
	g->v=n;
	g->AdjList = (struct node *) malloc(n*sizeof(struct node *));
	for(int i=0; i<n ;i++){
		NODE newnode = (struct node *) malloc(sizeof(struct node *));
		newnode->data=i;
		g->AdjList[i]->next = newnode;
	}
}

Graph addEdge(Graph g, int d1, int d2){
	for(int i=0; i<g->v; i++){
		if(d1==g->AdjList[i]->data)
		{
			NODE newnode = (struct node *) malloc (sizeof(struct node *));
			newnode->data=d2;
			NODE temp = g->AdjList[i];
			while(temp.next!=NULL)
				temp = newnode;
		}
		if(d2==g->AdjList[i]->data)
		{
			NODE newnode = (struct node *) malloc (sizeof(struct node *));
			newnode->data=d1;
			NODE temp = g->AdjList[i];
			while(temp.next!=NULL)
				temp = newnode;
		}
	}
}
int main()
{
	Graph g;
	g = createGraph(g,8);
	g.addEdge(4);
	return 0;
}
