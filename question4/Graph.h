#include "GraphTypes.h"

/*creates a Grapht*/
Graph *create(int nun);

/*initializes graph*/
void initialize(Graph *graph);

/*inser edge*/
void InserEdge(Vertex,Vertex,int,Graph*);

void AddVertex(Vertex vertex,Graph *graph);

void BreadthFirstSearch(Graph *g, void (*Visit)(Vertex));
void BreadthFirstSearch1(Graph *g, void (*Visit)(Vertex));

void ShowGraph(Graph* g);

int IsConnected(Graph* g);

void sort_edges(Graph* g);
List* Kruskal(Graph* G);

// ListNode createHeadNode(int );

// ListNode createNode(int );

// int get_data(ListNode m);

// /*returns list size*/
// int size(List list);

// /*returns "1" if list is empty else returns "0" */
// int isEmpty(List list);

// /*returns first node of the list*/
// ListNode getFirst(List list);

// /*takes as second parametre data of a new node and adds it at the begginig 
// of the list */     
// void init(List list,int data);

// /*takes as second parametre data of a node and removes it from the list */     
// void Remove(List list,int data);

/*prints graph*/
void ShowGraph(Graph *graph);


// int randLevel();

// ListNode search(List list,int data);

// List merge_lists1(List l1 ,List l2);

// List merge_lists2(List l1 ,List l2);

List* PathFinder(Graph *g , int Start,int Finish);

int graphSize(Graph *g);


List** ShortestPaths(Graph *g , int Start);