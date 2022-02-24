/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 6
* Date: February 23, 2022
* Description: Queues
*/

#pragma once

#include <iostream>
#include "QueueNode.h"

class Queue
{
public:
	bool isEmpty();
	
	Queue(QueueNode* newpHead = nullptr, QueueNode* newpTail = nullptr);

	bool enqueue(std::string newData);

	// precondition: queue is not empty
	std::string dequeue();

	QueueNode* getPHead();
	QueueNode* getPTail();

	void setPHead(QueueNode* newPHead);
	void setPTail(QueueNode* newPTail);

	
private:
	QueueNode* mpHead;
	QueueNode* mpTail;
};

void printQueueRecursive(QueueNode* pHead);