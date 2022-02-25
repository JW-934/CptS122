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

	bool enqueue(const std::string &newPrintJob); // bool b = false; (ex)

	bool isEmpty();

	// precondition: queue must not be empty
	std::string dequeue();

private:
	Node* mpHead;
	Node* mpTail;

	void destroyQueue();
};