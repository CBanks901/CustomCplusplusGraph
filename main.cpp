#include <iostream>
#include <string>
#include <conio.h>
#include "Graph.h"
#include "PQ.h"
#include <limits>


using namespace std;


 struct Item
{
	bool operator<(Item otherItem);
	bool operator==(Item otherItem);
	bool operator<=(Item otherItem);
	VertexType fromVertex;
	VertexType toVertex;
	int distance;
};

void ShortestPath(Graph graph, VertexType startVertex)
{
	
	using namespace std;
	
   
	//Item ItemType;
   Item item;
	//VertexType item2;
	int minDistance;
	
	PQType pq(10);

	QueType vertexQ;
	VertexType vertex;
	
	graph.ClearMarks();
	item.fromVertex = item.toVertex;
	item.toVertex = startVertex;
	item.distance = 0;
	
	 pq.Enqueue(item.distance);
	 cout << "\nLast Vertex Destination Distance" << endl;
	 cout << "--------------------------------" << endl;
	do
	{
		pq.Dequeue(item.distance);
		if (!graph.isMarked(item.toVertex) )
		{
			graph.MarkVertex(item.toVertex);
			cout << item.fromVertex;
			cout << "\n  ";
			cout << item.toVertex;
			cout << " " << item.distance << endl;
			item.fromVertex = item.toVertex;
			minDistance = item.distance;
			graph.GetToVertices(item.fromVertex, vertexQ);

			while (!vertexQ.isEmpty() )
			{
				vertexQ.Dequeue(vertex);
				if (!graph.isMarked(vertex) )
				{
					item.toVertex = vertex;
					item.distance = minDistance + graph.GetWeight(item.fromVertex, vertex);
					pq.Enqueue(item.distance);
				}
			}
		}
	} while (!pq.isEmpty() );
}




int main()
{
	using namespace std;
    Graph stringgraph;	// instantiation of a graph object with the default constructor
	cout << "                                 Preloaded Example \n\n";
	stringgraph.MakeEmpty();		// initalizes the graph to an empty state
	if (stringgraph.isEmpty() )
		cout << "The graph is empty.\n";
	else cout << "The graph is not empty.\n";
	// The seven preset vertices from lab documentation
	string d("Dallas");
	string c("Chicago");
	string dd("Denver");
	string a("Atlanta");
	string h("Houston");
	string aa("Austin");
	string w("Washington");
	// Adds the seven Vertices to the graph
	stringgraph.AddVertex(aa);
	stringgraph.AddVertex(h);
	stringgraph.AddVertex(d);
	stringgraph.AddVertex(dd);
	stringgraph.AddVertex(a);
	stringgraph.AddVertex(c);
	stringgraph.AddVertex(w);
	// Creates the edges specified in the lab document
	stringgraph.AddEdge(aa, d, 200);	// From Austin to Dallas
	stringgraph.AddEdge(aa, h, 160);	// From Austin to Houston
	stringgraph.AddEdge(d, aa, 200);		// From Dallas to Austin
	stringgraph.AddEdge(d, c, 900);		// From Dallas to Chicago
	stringgraph.AddEdge(d, dd, 780);			// From Dallas to Denver
	stringgraph.AddEdge(c, dd, 1000);				//From Chicago to Denver
	stringgraph.AddEdge(dd, c, 1000);				// From Denver to Chicago
	stringgraph.AddEdge(dd, a, 1400);				// From Denver to Atlanta
	stringgraph.AddEdge(h, a, 800);				// From Houston to Atlanta
	stringgraph.AddEdge(a, h, 800);				// From Atlanta to Houston
	stringgraph.AddEdge(a, w, 600);				// From Atlanta to Washington
	stringgraph.AddEdge(w, a, 600);				// From Washington to Atlanta
	stringgraph.AddEdge(w, d, 1300);		// From Washington to Dallas

	stringgraph.GetWeight(d, dd);
	QueType vertexQ;
	
	stringgraph.GetToVertices(w, vertexQ);
	//stringgraph.Dikjstra(stringgraph, w);
	ShortestPath(stringgraph, aa);

	  // pause
      cout << "\nPress any key to continue...";
      cin.sync();
       _getch();

      // return environment variable
      return 0;
} 