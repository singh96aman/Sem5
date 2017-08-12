#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}*NODE;

typedef struct adjlist{
  NODE *head;
}*Adjlist;

typedef struct graph{
  int V;
  Adjlist *array;
}*Graph;

Graph createGraph(int v){
  Graph newGraph;
  newGraph=(struct graph *)malloc(sizeof(struct graph *));
  newGraph->V=v;
  newGraph->array=(struct adjlist *)malloc(sizeof(struct adjlist *)*v);
  int i;
  for(i=0; i<v; i++)
    newGraph->array[i]->head = NULL;
  return newGraph;
}

void addEdge(Graph g, int src, int dest){
  int i;
  NODE cur;
  NODE newnode = (struct node *) malloc(sizeof(struct node *));
  newnode->data=dest;
  newnode->next=NULL;

  cur=g->array[src]->head;
  while(cur->next)
    cur=cur->next;
  cur->next=newnode;
}

void printGraph(Graph g){
  NODE cur;
  int i;
  for(i=0; i<g->V; i++){
    cur = g->array[i]->head;
    while(cur){
      printf("%d ",cur->data);
      cur=cur->next;
    }
    printf("\n");
  }
}

int main()
{
  int V=5;
  Graph g = createGraph(V);
  addEdge(g, 0, 1);
  addEdge(g, 0, 2);
  addEdge(g,1,3);
  addEdge(g, 4, 5);
  addEdge(g, 2, 4);
  printGraph(g);
}
