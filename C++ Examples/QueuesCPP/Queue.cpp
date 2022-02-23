#include "Queue.h"

Queue::Queue(Node* newpHead = nullptr, Node* newpTail = nullptr)
{
	this->mpHead = newpHead; // pointer assignment
	this->mpTail = newpTail;
}

bool Queue::enqueue(std::string newPrintJob)
{
	Node* pMem = new Node(newPrintJob); // calls Node constructor; replaces makeNode() from C
	bool success = false;

	if (pMem != nullptr)
	{
		success = true;
		
		if (isEmpty())
		{
			this->mpHead = this->mpTail = pMem; // both set to pMem
		}
		else
		{
			// not empty queue
			this->mpTail->setNextPtr(pMem); // this->mpNext->mpNext not possible
			this->mpTail = pMem;
		}
	}
	return success;
}

bool Queue::isEmpty()
{
	return this->mpHead == nullptr;
}

// precondition: queue must not be empty
std::string Queue::dequeue()
{
	Node* pTemp = this->mpHead;

	if (this->mpHead == this->mpTail)
	{
		// one node in queue
		this->mpHead = this->mpTail = nullptr;
	}
	else
	{
		// more than one node
		this->mpHead = 
	}
}