/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA5
* Date: March 5, 2022, March 10, 2022
* Description: A grocery store simulation utilizing queues.
*/

#include "Queue.h"

Queue::Queue(QueueNode* newpHead, QueueNode* newpTail)
{
	this->mpHead = newpHead; // pointer assignment
	this->mpTail = newpTail;
}

Queue::Queue()
{
	mpHead = nullptr;
	mpTail = nullptr;
}

Queue::~Queue()
{
	destroyQueue();
}

// getters
QueueNode* Queue::getPHead()
{
	return mpHead;
}

QueueNode* Queue::getPTail()
{
	return mpTail;
} 

// setters
void Queue::setPHead(QueueNode* newPHead)
{
	mpHead = newPHead;
}
void Queue::setPTail(QueueNode* newPTail)
{
	mpTail = newPTail;
}

bool Queue::enqueue(const int newNumber, const int newServTime, const int newTotalTime)
{
	QueueNode* pMem = new QueueNode(newNumber, newServTime, newTotalTime); // calls Node constructor; replaces makeNode() from C; int *ptr = new int[50], delete [] ptr
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
Data Queue::dequeue()
{
	QueueNode* pTemp = this->mpHead;

	if (this->mpHead == this->mpTail)
	{
		// one node in queue
		this->mpHead = this->mpTail = nullptr;
	}
	else
	{
		// more than one node
		this->mpHead = this->mpHead->getNextPtr();
	}
	Data data = pTemp->getData();

	delete pTemp; // by default the destructor for a Node is invoked (destructor for indirect type)

	return data;
}

// Private member function
void Queue::destroyQueue()
{
	//delete this;
	while (!isEmpty())
	{
		dequeue();
		//delete this->mpHead;
	}
}

// Non member functions
void printQueueRecursive(QueueNode* pHead)
{
	if (pHead == nullptr)
	{
		std::cout << std::endl;
		return;
	}
	else
	{
		std::cout << "Customer: " << pHead->getData().getNumber() << " Service Time: " << pHead->getData().getServTime() << " Total Time: " << pHead->getData().getTotalTime() << std::endl;
		printQueueRecursive(pHead->getNextPtr());
	}
}