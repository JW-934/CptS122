/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA5
* Date: March 5, 2022
* Description: A grocery store simulation utilizing queues.
*/

#pragma once

#include <iostream>

#include "Data.h"

class QueueNode
{
public:
	QueueNode(const int newNumber = 0, const int newServiceTime = 0, const int newTotalTime = 0);

	~QueueNode();

	void setNextPtr(QueueNode* newNextPtr);
	QueueNode* getNextPtr() const;

	Data getData() const;
private:
	Data* pData;
	QueueNode* pNext;
};

