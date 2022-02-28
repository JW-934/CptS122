#pragma once

#include <iostream>
#include "Node.h"

using std::cin;
using std::cout;
using std::endl;

template <class T> // by default everything in Queue class becomes generic type T
class Queue
{
public:
	Queue(Node<T>* newpHead, Node<T>* newpTail); // going to need a Node template too
	Queue();

	~Queue();

	bool enqueue(const T &newPrintJob); // bool b = false; (ex)

	bool isEmpty();

	// precondition: queue must not be empty
	T dequeue();

private:
	Node<T>* mpHead;
	Node<T>* mpTail;

	void destroyQueue();
};

template <class T>
Queue<T>::Queue(Node<T>* newpHead, Node<T>* newpTail)
{
	this->mpHead = newpHead; // pointer assignment
	this->mpTail = newpTail;
}

template <class T>
Queue<T>::Queue()
{
	mpHead = nullptr;
	mpTail = nullptr;
}

template <class T>
Queue<T>::~Queue()
{
	destroyQueue();
}

template <class T>
bool Queue<T>::enqueue(const T& newPrintJob)
{
	Node<T>* pMem = new Node<T>(newPrintJob); // calls Node constructor; replaces makeNode() from C; int *ptr = new int[50], delete [] ptr
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

template <class T>
bool Queue<T>::isEmpty()
{
	return this->mpHead == nullptr;
}

// precondition: queue must not be empty
template <class T>
T Queue<T>::dequeue()
{
	Node<T>* pTemp = this->mpHead;

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
	T data = pTemp->getData();

	delete pTemp; // by default the destructor for a Node is invoked (destructor for indirect type)

	return data;
}

// Private member function
template <class T>
void Queue<T>::destroyQueue()
{
	//delete this;
	while (!isEmpty())
	{
		dequeue();
		//delete this->mpHead;
	}
}