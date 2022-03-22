#include "Graph.h"
#include "PQ.h"
#include <iostream>
using namespace std;
#define infinity 1000
#define undefined -1

Graph::Graph()
{
	numVertices = 0;
	maxVertices = 50;
	vertices = new VertexType[50];
	marks = new bool[50];
}

Graph::Graph(int maxV)
{
	numVertices = 0;
	maxVertices = maxV;
	vertices = new VertexType[maxV];
	marks = new bool[maxV];
}

Graph::~Graph()
{
	delete [] vertices;
	delete [] marks;
}

const int NULL_EDGE = 0;

bool Graph::isEmpty() const
{
	return numVertices == 0;
}

bool Graph::isFull() const
{
	return numVertices == 50;		// if the graph is equal to the maximum number of Verticies fifty in this case
}

void Graph::AddVertex(VertexType vertex)
{
	vertices[numVertices] = vertex;

	for (int index = 0; index < numVertices; index++)
	{
		edges[numVertices][index] = NULL_EDGE;
		edges[index][numVertices] = NULL_EDGE;
	}
	numVertices++;
	cout << "Vertex added. \nNumber of vertices: " << numVertices << endl;
}

int IndexIs(VertexType * vertices, VertexType vertex)
{
	int index = 0;

	while (!(vertex == vertices[index]))
		index++;
	return index;
}

void Graph::AddEdge(VertexType fromVertex, VertexType toVertex, int weight)
{
	int row;
	int col;

	row = IndexIs(vertices, fromVertex);
	col = IndexIs(vertices, toVertex);
	edges[row][col] = weight;
}

int Graph::GetWeight(VertexType fromVertex, VertexType toVertex)
{
	int row;
	int col;

	row = IndexIs(vertices, fromVertex);
	col = IndexIs(vertices, toVertex);
	cout << "Current weight from " << fromVertex << " to " << toVertex << " is: " << edges[row][col] << endl;
	return edges[row][col];
}


void Graph::GetToVertices(VertexType vertex, QueType& adjVertices)
{
	int fromIndex;
	int toIndex;

	fromIndex = IndexIs(vertices, vertex);
	for (toIndex = 0; toIndex < numVertices; toIndex++)
	{
		if (edges[fromIndex][toIndex] != NULL_EDGE)
		{  
			adjVertices.Enqueue(vertices[toIndex]);
			adjVertices.Display();		// calls the display function to print out the adjacent vertices in the queue
		}
	}
	
	
}

void Graph::ClearMarks()
{
	for (int i = 0; i < numVertices; i++)
		marks[i] = 0;
}

void Graph::MarkVertex(VertexType vertex)
{
	int i = 0;
	while (i != numVertices)
	{
		i++;

	}
	marks[i] = true;		// marks the vertex as true
	vertex = marks[i];
	
}

bool Graph::isMarked(VertexType vertex) 
{
	/*int i = numVertices;
	marks[numVertices];
	if (marks[numVertices])
		return true;
	else return false;
	*/
	for (int i = 0; i < numVertices; i++)
	{
		vertex = i;
		if (marks[i] && vertices)
		{
			//vertex = true;
			marks[i] = true;
			return marks[i];
		}
		else 
		{
			
			marks[i] = false;
			return marks[i];
		}
	}
	
}
void Graph::MakeEmpty() 
{
	for (int i = 0; i < numVertices; i++)	// uses a for loop to handle every single verticies
		marks[i] = 0;						// sets every vertex to zero
	numVertices = 0;
	vertices = new VertexType[50];
	marks = new bool[50];
	cout << "Graph is now initalized.\n";
}
/*
void Graph::Dikjstra(Graph graph, VertexType vertex)
{
	for (int i = 0; i < numVertices; i++)
	{
		marks[i] = 0;
		dist[i] = infinity;
		previous[i] = undefined;
	}
	
	dist[0] = 0;
	vertex = dist[0];

	int minDistance = infinity;
	int unmarked;
	for (int i = 0; i < numVertices; i++)
	{
		if (!marks[i] && (minDistance >= dist[i]) )
		{
			minDistance = dist[i];
			unmarked = i;
		}
	
	int count = 0;
	while (count < numVertices)
	{
		marks[unmarked] = true;
		for (int i = 0; i < numVertices; i++)
		{
			if ((!marks[i]) && (edges[unmarked][i] > 0))
			{
				if (dist[i] > dist[unmarked]+edges[unmarked][i])
				{
					dist[i] = dist[unmarked] + edges[unmarked][i];
					previous[i] = unmarked;
				}
		}
	}

   }count++;
	cout << unmarked << "\n";
}

}*/