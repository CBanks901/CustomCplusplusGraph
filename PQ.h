// Priority Queue ADT
#include <string>

typedef int Type;
struct HeapType
{
	void ReheapDown(int root, int bottom);
	void ReheapUp(int root, int bottom);
	Type* elements;
	int numElements;
};


class FullPQ
{};
class EmptyPQ
{};



typedef int Type;
class PQType
{
public:
	PQType(int);
	~PQType();
	void MakeEmpty();
	bool isEmpty() const;
	bool isFull() const;
	void Enqueue(Type newitem);
	void Dequeue(Type& item);
private:
	int length;
	HeapType items;
	int maxItems;
};


