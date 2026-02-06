#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "List.h"

int main(){

	int num=9;  //number of vertices in the graph up to MAXVERTEX)
	Graph *g=create(num);

	initialize(g);
	AddVertex(0,g);
	AddVertex(1,g);
	AddVertex(2,g);
	AddVertex(3,g);
	AddVertex(4,g);
	AddVertex(5,g);
	AddVertex(6,g);
	AddVertex(7,g);
	AddVertex(8,g);
	

	InserEdge(0,1,100,g);
	InserEdge(1,2,3,g);
	InserEdge(2,3,7,g);
	InserEdge(3,4,10,g);
	InserEdge(4,5,2,g);
	InserEdge(5,6,1,g);
	InserEdge(6,7,8,g);
	InserEdge(7,8,5,g);
	InserEdge(8,0,4,g);

	List result=Kruskal(g);
	printList(result);


	
	//ShowGraph(g);

	return 0;
}