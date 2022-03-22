#include <string>
#include <iostream>


typedef std::string ItemType;

class QueType 
{
public:
	
	QueType();			// Default constructor 
	~QueType();			// Default destructor
	void MakeEmpty();
	bool isEmpty() const;
	bool isFull() const;
	void Enqueue(ItemType newitem);
	void Dequeue(ItemType& item);
	void Display();

private:
	int front;
	int rear;
	ItemType* items;
	int maxQueue;
	int emptyItem;
	
};
