/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 6
* Date: February 23, 2022
* Description: Queues
*/

#include "Queue.h"
#include "QueueNode.h"

Queue::Queue(QueueNode* newpHead, QueueNode* newpTail)
{
	mpHead = newpHead;
	mpTail = newpTail;
}

bool Queue::isEmpty()
{
	return (mpHead == nullptr);
}

bool Queue::enqueue(std::string newData)
{
	bool success = false;
	QueueNode* pMem = new QueueNode(newData);

	if (isEmpty())
	{
		// empty queue
		mpHead = pMem;
		mpTail = pMem;
		success = true;
	}
	else
	{
		// non empty queue
		mpTail->setNextPtr(pMem);
		
		this->mpTail = pMem;
		
		success = true;
	}
	return success;
}

 // precondition: queue is not empty
std::string Queue::dequeue()
{
	QueueNode* pTemp = this->mpHead;
	std::string data = mpHead->getData();

	if (mpHead == mpTail)
	{
		// one node in queue
		mpHead = mpTail = nullptr;
	}
	else
	{
		// more than one node in queue
		mpHead = mpHead->getNextPtr();
	}

	delete pTemp;

	return data;
}

void Queue::printQueueRecursive(QueueNode* pHead)
{
	if (pHead == nullptr)
	{
		std::cout << std::endl;
		return;
	}
	else
	{
		std::cout << pHead->getData() << std::endl;
		printQueueRecursive(pHead->getNextPtr());
	}
}

QueueNode* Queue::getPHead()
{
	return mpHead;
}

QueueNode* Queue::getPTail()
{
	return mpTail;
}

void Queue::setPHead(QueueNode* newPHead)
{
	mpHead = newPHead;
}
void Queue::setPTail(QueueNode* newPTail)
{
	mpTail = newPTail;
}