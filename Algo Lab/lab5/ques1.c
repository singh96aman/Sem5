#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}*Node;

typedef struct adjlist{
	struct adjlist *head;
}*Adjlist;

typedef struct graph{
	int v;
	struct adjlist *list;
}*Graph;

Graph createGraph(int V){
	Graph g = (Graph) malloc(sizeof(struct graph *));
	g->v = V;
	g->list = (Adjlist) malloc(sizeof(struct adjlist *)*V);
	for(int i=0; i<V; i++)
		g->list[i].head=NULL;
	return g;
}

Graph addEdge(Graph g,int a, int b){
	Node newnode = (Node) malloc(sizeof(struct node *));
	newnode->data=b;
	newnode->next=NULL;
	newnode->next = g->list[a].head;
    g->list[a].head = newnode;
}

void printGraph(Graph g){
	for(int i=0; i<g->v; i++)
	{
		Node temp = g->list[i].head;
		printf("\n Adjacency list of vertex %d\n",i);
		while(temp){
			printf("%d ",temp->data);
			temp = temp->next;
		}
	}
	printf("\n");
}

void main()
{
	int V=5;
	Graph g = createGraph(V);
	g = addEdge(g, 0, 1);
    g = addEdge(g, 0, 4);
    g = addEdge(g, 1, 2);
    g = addEdge(g, 1, 3);
    g = addEdge(g, 1, 4);
    g = addEdge(g, 2, 3);
    g = addEdge(g, 3, 4);
    printGraph(g);	
}