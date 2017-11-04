#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *link;
}*Node;

typedef struct adjlist
{
	struct node *head;
}*Adjlist;

typedef struct graph
{
	int v;
	struct adjlist *array;
}*Graph;

Graph createGraph(Graph g, int n)
{
	g = (struct graph *) malloc(sizeof(struct graph));
	g->v=n;
	g->array = (struct adjlist *) malloc(n*sizeof(struct adjlist));
	for(int i=0; i<n; i++)
		g->array[i].head=NULL;
	return g;
}

Graph addEdge(Graph g, int a, int b)
{
	Node temp = (struct node *) malloc(sizeof(struct node));
	temp->data=b;
	temp->link=NULL;
	//temp->link = g->array[a].head;
	//g->array[a].head=temp; 
	Node travel=g->array[a];
	if(travel==NULL)
		travel=temp;
	else
	{
		while(travel->link)
			travel=travel->link
		travel->link=temp;
	}
	return g;
}

void print(Graph g)
{
	int n=g->v;
	for(int i=0; i<n; i++)
	{
		Node temp=g->array[i].head;
		printf("%d ",i);
		while(temp)
		{
			printf("%d ",temp->data);
			temp=temp->link;
		}
		printf("\n");
	}
}

int main()
{
	Graph g = createGraph(g, 4);
	g=addEdge(g,0,1);
	g=addEdge(g,1,2);
	g=addEdge(g,1,3);
	print(g);
}