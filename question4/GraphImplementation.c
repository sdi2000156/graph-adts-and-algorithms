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
	// same for sortededge
	for (int i = 0; i < graph->n; i++)
	{
		graph->sorted_edges[i] = malloc(sizeof(Edge));
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

void InserEdge(Vertex source, Vertex destiation, int weight, Graph *graph)
{

	int i = search(graph, source);
	int j = search(graph, destiation);

	graph->firstedge[i]->nextedge = graph->firstedge[j];
	graph->revedge[j]->prevedge = graph->revedge[i];
	graph->firstedge[i]->weight = weight;
	graph->revedge[j]->weight = weight;
}

void ShowGraph(Graph *graph)
{

	Edge *current;

	for (int i = 0; i < graph->n; i++)
	{
		printf("------------\n");
		printf("Vertex %d has value %d \n", i, graph->data[i]);
		// search for the vertex in the firstedge array
		int pos = search(graph, graph->firstedge[i]->endpoint);
		if (pos == -1)
		{
			printf("Vertex %d is not connected to any other vertex \n", i);
			continue;
		}
		if (graph->firstedge[pos]->nextedge != NULL)
		{
			printf("Vertex %d is connected to %d  and weight is  %d  \n", pos, graph->firstedge[pos]->nextedge->endpoint, graph->firstedge[pos]->nextedge->weight);
		}
		if (graph->revedge[pos]->prevedge != NULL)
		{
			printf("Vertex %d is connected to %d and weight is %d \n", pos, graph->revedge[pos]->prevedge->endpoint, graph->revedge[pos]->prevedge->weight);
		}
		printf("------------\n");
	}
}

void Visit(Vertex vertex)
{
	printf("Vertex %d visited\n", vertex);
}

List *lst;
void VisitLst(Vertex vertex)
{
	addFirst(lst, vertex);
}

// make BFS cheking revedge as well
void BreadthFirstSearch1(Graph *graph, int start, void (*Visit)(Vertex))
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
	int r = start; // for the first vertex index
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
	BreadthFirstSearch1(g, 0, VisitIncrease);
	if (count == g->n)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

List *l1;
List *l2;
VisitAddToList1(Vertex vertex)
{
	addFirst(l1, vertex);
}
VisitAddToList2(Vertex vertex)
{
	addFirst(l2, vertex);
}

void sort_edges(Graph *g)
{
	// sort edges based on their weights in ascending order and store them to sorted_edges array
	Edge *temp;
	
		for (int i = 0; i < g->n; i++)
		{
			for (int j = 0; j < g->n; j++)
			{
				if (g->firstedge[i]->weight < g->firstedge[j]->weight)
				{
					Edge *temp2 = g->firstedge[j];
					g->firstedge[j] = g->firstedge[i];
					g->firstedge[i] = temp2;

					// swap the vertices in data array
					Vertex temp3 = g->data[j];
					g->data[j] = g->data[i];
					g->data[i] = temp3;
				}
			}
		}

		
	
	
}

List *Kruskal(Graph *G)
{
	Graph *temp = create(G->n);
	initialize(temp);
	// if graph is not connected return null
	if (!IsConnected(G))
	{
		return NULL;
	}
	// sort edges
	// sort_edges(G,1);
	int i = 0;
	List *result1 = createList();
	int total1 = 0;

	// print graph vertices
	sort_edges(G);
	int maxindex1;
	maxindex1=0;
	int maxCount = 0;
	do
	{
		if (search(temp, G->firstedge[i]->endpoint) == -1)
		{
			AddVertex(G->firstedge[i]->endpoint, temp);
			addFirst(result1, G->firstedge[i]->endpoint);
		}
		if (search(temp, G->firstedge[i]->nextedge->endpoint) == -1)
		{
			AddVertex(G->firstedge[i]->nextedge->endpoint, temp);
			addFirst(result1, G->firstedge[i]->nextedge->endpoint);
		}
		// print the edge
		InserEdge(G->firstedge[i]->endpoint, G->firstedge[i]->nextedge->endpoint, G->firstedge[i]->weight, temp);
		total1 += G->firstedge[i]->weight;
		count = 0;
		count = 0;
		maxCount = 0;
		for(int j=0 ; j<=i;j++){
			count=0;
		BreadthFirstSearch1(temp, j, VisitIncrease);
		
		if (count > maxCount)
		{
			maxCount = count;
			maxindex1 = j;
		}
		}
			
	

		i++;
	} while (maxCount != G->n && i < G->n);

	
	printf("Minimum path cost is : %d \n", total1);
		lst = createList();
		BreadthFirstSearch1(temp, maxindex1, VisitLst);
		return lst;
	
}
