#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "List.h"

void Visit1(Vertex vertex)
{
	printf("Vertex %d visited\n", vertex);
}

int main()
{

	int num;
	printf("Please give number of vertices in the graph (up to %d)\n",MAXVERTEX);
	scanf("%d",&num);

	Graph *g = create(num);

	initialize(g);

	AddVertex(0, g);
	AddVertex(1, g);
	AddVertex(2, g);
	AddVertex(3, g);
	AddVertex(4, g);
	AddVertex(5, g);
	AddVertex(6, g);
	AddVertex(7, g);
	AddVertex(8, g);
	AddVertex(9, g);
	printf("Vertex added\n");

	InserEdge(0, 1, g);
	InserEdge(2, 4, g);
	InserEdge(1, 3, g);
	InserEdge(4, 5, g);
	InserEdge(5, 6, g);
	InserEdge(6, 7, g);
	InserEdge(7, 0, g);
	InserEdge(3, 2, g);
	InserEdge(8, 9, g);
	ShowGraph(g);

	BreadthFirstSearch1(g, Visit1);

	if (IsConnected(g)){
		printf("Graph is connected\n");
	}
	else{
		printf("Graph is not connected\n");
	}

	int gsize=graphSize(g);

	List** lists=ShortestPaths(g, 0);
	
	for(int i=0;i<gsize;i++){
		printf("Path from 0 to %d: ",i);
		if(lists[i]==NULL){
			printf("No path exists\n");
		}
		else{
			printList(lists[i]);
		}
	}

	return 0;
}