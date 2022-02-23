#pragma once

#include <iostream>
#include "Node.h"

using std::cin;
using std::cout;
using std::endl;

class Queue
{
public:
	Queue(Node* newpHead = nullptr, Node* newpTail = nullptr);

	bool enqueue(std::string newPrintJob); // bool b = false; (ex)

	bool isEmpty();

	// precondition: queue must not be empty
	std::string dequeue();

private:
	Node* mpHead;
	Node* mpTail;
};