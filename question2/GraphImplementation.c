#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "List.h"
#include "GraphTypes.h"
#include "PQInterface.h"

#define NULLITEM -1



Graph *create(int num)
{

	Graph *graph = malloc(sizeof(*graph));

	graph->max_vertexes = num;
	graph->n = num;

	return graph;
}

void initialize(Graph *graph)
{

	for (int i = 0; i < graph->n; i++)
	{
		graph->firstedge[i] = malloc(sizeof(Edge));
	}
	// same for revedge
	for (int i = 0; i < graph->n; i++)
	{
		graph->revedge[i] = malloc(sizeof(Edge));
	}
	// initialize vertexes
	for (int i = 0; i < graph->n; i++)
	{
		graph->data[i] = malloc(sizeof(Vertex));
		*graph->data[i] = NULL;
	}
	graph->n = 0;
}

int graphSize(Graph *g)
{
	return g->n;
}


void AddVertex(Vertex vertex, Graph *graph)
{

	graph->data[graph->n] = vertex;
	graph->firstedge[graph->n]->endpoint = vertex;
	graph->revedge[graph->n]->endpoint = vertex;
	graph->n++;
}

int search(Graph *graph, Vertex vertex)
{

	for (int i = 0; i < graph->n; i++)
	{
		if (graph->firstedge[i]->endpoint == vertex)
		{
			return i;
		}
	}
	return -1;
}

void InserEdge(Vertex source, Vertex destiation, Graph *graph)
{

	int i = search(graph, source);
	int j = search(graph, destiation);

	graph->firstedge[i]->nextedge = graph->firstedge[j];
	graph->revedge[j]->prevedge = graph->revedge[i];
}

void ShowGraph(Graph *graph)
{

	Edge *current;

	for (int i = 0; i < graph->n; i++)
	{
		printf("------------\n");
		printf("Vertex %d has value %d \n", i, graph->data[i]);
		if (graph->firstedge[i]->nextedge != NULL)
		{
			printf("Vertex %d is connected to %d \n", i, graph->firstedge[i]->nextedge->endpoint);
		}
		if (graph->revedge[i]->prevedge != NULL)
		{
			printf("Vertex %d is connected to %d \n", i, graph->revedge[i]->prevedge->endpoint);
		}
		printf("------------\n");
	}
}

void Visit(Vertex vertex)
{
	printf("Vertex %d visited\n", vertex);
}

void BreadthFirstSearch(Graph *graph, void (*Visit)(Vertex))
{

	PriorityQueue *queue = malloc(sizeof(*queue));
	Initialize(queue);
	int visited[graph->n];

	for (int i = 0; i < graph->n; i++)
	{
		visited[i] = 0;
	}

	Vertex current;
	Vertex temp;
	int i;
	int j;

	for (int r = 0; r < graph->n; r++)
	{
		if (visited[r] == 0)
		{
			visited[r] = 1;
			Visit(graph->data[r]);
			Insert(graph->data[r], queue);
			// printf("fine 1\n");
			while (!isEmpty(queue))
			{
				current = Remove(queue);
				i = search(graph, current);
				if (i != -1 && graph->firstedge[i]->nextedge != NULL)
				{
					current = graph->firstedge[i]->nextedge->endpoint;
				}
				else
				{
					current = NULLITEM;
				}
				while (current != NULLITEM)
				{
					// printf("fine 2 j  is %d\n",j);
					j = search(graph, current);
					if (j == -1)
					{
						break;
					}
					if (visited[j] == 0)
					{
						visited[j] = 1;
						Visit(graph->data[j]);
						Insert(graph->data[j], queue);
					}
					else
					{
						return;
					}

					if (graph->firstedge[j]->nextedge != NULL)
					{
						current = graph->firstedge[j]->nextedge->endpoint;
					}
					else
					{
						current = NULLITEM;
					}
				}
			}
		}
	}
}

// make BFS cheking revedge as well
void BreadthFirstSearch1(Graph *graph, void (*Visit)(Vertex))
{
	PriorityQueue *queue = malloc(sizeof(*queue));
	Initialize(queue);
	int visited[graph->n];
	int processed[graph->n];

	int break_counter = 0;

	for (int i = 0; i < graph->n; i++)
	{
		visited[i] = 0;
		processed[i] = 0;
	}

	Vertex current;
	int i, j;
	int r=0; // for the first vertex index
	// for (int r = 0; r < graph->n; r++)
	// {
		if (visited[r] == 0)
		{
			visited[r] = 1;
			Visit(graph->data[r]);
			Insert(graph->data[r], queue);

			while (!isEmpty(queue))
			{
				current = Remove(queue);
				i = search(graph, current);

				break_counter = 0;
			

				if (i != -1 && processed[i] == 0)
				{
					processed[i] = 1;
					Edge *edge = graph->firstedge[i];

					while (edge != NULL)
					{
						current = edge->endpoint;
						j = search(graph, current);

						if (j != -1 && visited[j] == 0 && processed[j] == 0)
						{
							processed[j] = 1;
							visited[j] = 1;
							Visit(graph->data[j]);
							Insert(graph->data[j], queue);
						}
						edge = edge->nextedge;
						break_counter++;
						if (break_counter > graph->n)
						{
							break;
						}
					}
				}
				break_counter = 0;
					if (i != -1 && processed[i] == 0)
				{
					processed[i] = 1;
					Edge *edge = graph->revedge[i];

					while (edge != NULL)
					{
						current = edge->endpoint;
						j = search(graph, current);

						if (j != -1 && visited[j] == 0 && processed[j] == 0)
						{
							visited[j] = 1;
							Visit(graph->data[j]);
							Insert(graph->data[j], queue);
						}

						edge = edge->prevedge;
						break_counter++;
						if (break_counter > graph->n)
						{
							break;
						}
					}
				}
				
				break_counter = 0;
				processed[i] = 1;
			}
		}
	// }
}

static count = 0;
VisitIncrease(Vertex vertex)
{
	count++;
}

int IsConnected(Graph *g)
{
	count = 0;
	BreadthFirstSearch1(g, VisitIncrease);
	if (count == g->n)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}





List* l1;
List* l2;
VisitAddToList1(Vertex vertex)
{
	addFirst(l1, vertex);
}
VisitAddToList2(Vertex vertex)
{
	addFirst(l2, vertex);
}



void customBFS_direction1(Graph *graph,int start,int target,void (*Visit)(Vertex))
{
	PriorityQueue *queue = malloc(sizeof(*queue));
	Initialize(queue);
	int visited[graph->n];
	int processed[graph->n];

	int break_counter = 0;

	for (int i = 0; i < graph->n; i++)
	{
		visited[i] = 0;
		processed[i] = 0;
	}

	Vertex current;
	int i, j;
	int r=start; // for the first vertex index
	// for (int r = 0; r < graph->n; r++)
	// {
		if (visited[r] == 0)
		{
			visited[r] = 1;
			Visit(graph->data[r]);
			Insert(graph->data[r], queue);
			if(graph->data[r]==target){
				return;
			}
			

			while (!isEmpty(queue))
			{
				current = Remove(queue);
				i = search(graph, current);

				break_counter = 0;
			

				if (i != -1 && processed[i] == 0)
				{
					processed[i] = 1;
					Edge *edge = graph->firstedge[i];

					while (edge != NULL)
					{
						current = edge->endpoint;
						j = search(graph, current);

						if (j != -1 && visited[j] == 0 && processed[j] == 0)
						{
							processed[j] = 1;
							visited[j] = 1;
							Visit(graph->data[j]);
							Insert(graph->data[j], queue);
							if(graph->data[j]==target){
								return;

							}
						}
						edge = edge->nextedge;
						break_counter++;
						if (break_counter > graph->n)
						{
							break;
						}
					}
				}
				break_counter = 0;
				processed[i] = 1;
			}
		}
	// }
}
void customBFS_direction2(Graph *graph,int start,int target,void (*Visit)(Vertex))
{
	PriorityQueue *queue = malloc(sizeof(*queue));
	Initialize(queue);
	int visited[graph->n];
	int processed[graph->n];

	int break_counter = 0;

	for (int i = 0; i < graph->n; i++)
	{
		visited[i] = 0;
		processed[i] = 0;
	}

	Vertex current;
	int i, j;
	int r=start; // for the first vertex index
	// for (int r = 0; r < graph->n; r++)
	// {
		if (visited[r] == 0)
		{
			visited[r] = 1;
			Visit(graph->data[r]);
			Insert(graph->data[r], queue);
				if(graph->data[r]==target){
				return;
			}
			

			while (!isEmpty(queue))
			{
				current = Remove(queue);
				i = search(graph, current);

				break_counter = 0;
				if (i != -1 && processed[i] == 0)
				{
					processed[i] = 1;
					Edge *edge = graph->revedge[i];

					while (edge != NULL)
					{
						current = edge->endpoint;
						j = search(graph, current);

						if (j != -1 && visited[j] == 0 && processed[j] == 0)
						{
							visited[j] = 1;
							Visit(graph->data[j]);
							Insert(graph->data[j], queue);
								if(graph->data[j]==target){
								return;

							}
						}

						edge = edge->prevedge;
						break_counter++;
						if (break_counter > graph->n)
						{
							break;
						}
					}
				}
				
				break_counter = 0;
				processed[i] = 1;
			}
		}
	// }
}



List* PathFinder(Graph *g , int Start,int Finish){
	//initialize the list
	l1 =createList();
	customBFS_direction1(g,Start,Finish,VisitAddToList1);
	//print list size and list
	// printf("list size %d\n",size(l1));
	// printList(l1);
	l2 =createList();
	customBFS_direction2(g,Start,Finish,VisitAddToList2);
	// printf("list size %d\n",size(l2));
	// printList(l2);
	List* result;
	if(size(l1)>size(l2)){
		result=l2;
	}else{
		result=l1;
	}
	return result;
}

List** ShortestPaths(Graph *g , int Start){
	List** result=malloc(sizeof(List*)*g->n);
	for(int i=0;i<g->n;i++){
		result[i]=PathFinder(g,Start,g->data[i]);
		if(get_data(getFirst(result[i]))!=g->data[i]){
			result[i]=NULL;
		}
		
	}
	return result;
}