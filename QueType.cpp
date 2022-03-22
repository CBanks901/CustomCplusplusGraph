#include "QueType.h"
#include <string.h>
#include <iostream>

class FullQueue
{};
class EmptyQueue
{};

using namespace std;


QueType::QueType()
{
	maxQueue = 10;		
	front = maxQueue - 1;
	rear = maxQueue - 1;
	items = new ItemType[maxQueue];
}

QueType::~QueType()
{
	delete [] items;
}

void QueType::MakeEmpty()
{
	front = maxQueue - 1;
	rear = maxQueue - 1;
}

bool QueType::isEmpty() const
{
	return (rear == front);
}

bool QueType::isFull() const
{
	return ((rear + 1) % maxQueue == front);
}

void QueType::Enqueue(ItemType newitem)
{
	
	if (isFull())
	{
		throw FullQueue();
		cout << "Queue is full \n";
		
	}
	else 
	{
		rear = (rear + 1) % maxQueue;
		items[rear] = newitem;
		cout << "Item queued\n";
	}
}

void QueType::Dequeue(ItemType& item)
{
	if (isEmpty())
	{
		cout << "Queue is empty \n";
		throw EmptyQueue();
	}
	else if (!isEmpty())
	{
		front = (front + 1) % maxQueue;
		item = items[front];
	}
}



void QueType::Display() 
{
	if (!isEmpty() && (!isFull() ) ) 
	{
		cout << items[rear] << endl;
	}
}
