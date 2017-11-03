// A C Program to demonstrate adjacency list representation of graphs
 
#include <stdio.h>
#include <stdlib.h>
 
// A structure to represent an adjacency list node
struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};
 
// A structure to represent an adjacency list
struct AdjList
{
    struct AdjListNode *head;  // pointer to head node of list
};
 
// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
    int V;
    struct AdjList* array;
};
 
// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
 
// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
 
    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
 
     // Initialize each adjacency list as empty by making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 
// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// A utility function to print the adjacenncy list representation of graph
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
 

int push_counter=0;
int pop_counter=0;

void dfs(struct Graph* g, int src, int visited[10], int push[10],int pop[10]){
	if(!visited[src]){
		visited[src]=1;
		//printf("%d\n",src);
		push[push_counter++]=src;
		if(g->array[src].head){
		struct AdjListNode* temp = g->array[src].head;
		//printf("%d\n\n",temp->dest);
		while(!visited[temp->dest]){
			//push[push_counter++]=temp->dest;
			dfs(g,temp->dest,visited,push,pop);
			if(temp->next)
				temp=temp->next;
		}
	}
	pop[pop_counter++]=src;
	}			
}

int main()
{
	int V = 4, i;
	struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 2);
     addEdge(graph, 0, 1);
	addEdge(graph, 1, 3);	
	addEdge(graph, 2, 3);
	int visited[4];
	printGraph(graph);
	for(i=0; i<V; i++)
		visited[i]=0;
	int push[4];
	int pop[4];
	for(i=0; i<V; i++)
		dfs(graph,0,visited,push,pop);
	for(i=0; i<V; i++)
		printf("%d ",push[i]);
	printf("\n");
	for(i=0; i<V; i++)
		printf("%d ",pop[i]);
	return 0;
}
