/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA5
* Date: March 5, 2022, March 10, 2022
* Description: A grocery store simulation utilizing queues.
*/

#pragma once

#include <iostream>

#include "QueueNode.h"
#include "Data.h"

class Queue
{
public:
	Queue(QueueNode* newpHead, QueueNode* newpTail); // going to need a Node template too
	Queue();

	~Queue();

	// getters
	QueueNode* getPHead();
	QueueNode* getPTail();

	// setters
	void setPHead(QueueNode* newPHead);
	void setPTail(QueueNode* newPTail);

	bool enqueue(const int newNumber, const int newServTime, const int newTotalTime); // bool b = false; (ex)

	bool isEmpty();

	// precondition: queue must not be empty
	Data dequeue();
private:
	QueueNode* mpHead;
	QueueNode* mpTail;

	void destroyQueue();
};

void printQueueRecursive(QueueNode* pHead);