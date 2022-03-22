#include "PQ.h"
#include <stdio.h>

void HeapType::ReheapDown(int root, int bottom)
{
	int maxChild;
	int rightChild;
	int leftChild;

	leftChild = root*2+1;
	rightChild = root*2+2;
	if (leftChild <= bottom)
	{
		if (leftChild == bottom)
			maxChild = leftChild;
		else 
		{
			if (elements[leftChild] <= elements[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
		if (elements[root] < elements[maxChild])
		{
			std::swap(elements[root], elements[maxChild]);
			ReheapDown(maxChild, bottom);
		}
	}
}

void HeapType::ReheapUp(int root, int bottom)
{
	int parent;

	if (bottom > root)
	{
		parent = (bottom-1)/2;
		if (elements[parent] < elements[bottom])
		{
			std::swap(elements[parent], elements[bottom]);
			ReheapUp(root, parent);
		}
	}
}

PQType::PQType(int max)
{
	maxItems = max;
	items.elements = new Type[max];
	length = 0;
}

PQType::~PQType()
{
	delete [] items.elements;
}


void PQType::MakeEmpty()
{
	length = 0;
}


void PQType::Dequeue(Type& item)
{
	if (length == 0)
		throw EmptyPQ();
	else 
	{
		item = items.elements[0];
		items.elements[0] = items.elements[length-1];
		length--;
		items.ReheapUp(0, length-1);
	}
}
		

void PQType::Enqueue(Type newitem)
{
	if (length == maxItems)
		throw FullPQ();
	else 
	{
		length++;
		items.elements[length-1] = newitem;
		items.ReheapUp(0, length-1);
	}

}


bool PQType::isFull() const
{
	return length == maxItems;
}


bool PQType::isEmpty() const
{
	return length == 0;
}

