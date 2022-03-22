#include <string>
#include "QueType.h"

typedef std::string VertexType;
class Graph
{
public:
	Graph();
	Graph(int maxV);
	~Graph();
	void MakeEmpty();
	bool isEmpty() const;
	bool isFull() const;
	void AddVertex(VertexType);
	void AddEdge(VertexType, VertexType, int);
	int GetWeight(VertexType, VertexType);
	void GetToVertices(VertexType, QueType&);
	void ClearMarks();
	void MarkVertex(VertexType);
	bool isMarked(VertexType);
//	void Dikjstra(Graph graph, VertexType startVertex);		// Dikjstra method

private:
	int numVertices;
	int maxVertices;
	VertexType* vertices;
	int edges[50][50];
	bool* marks;
	int dist[50], previous[50];	// previous and distance 
};