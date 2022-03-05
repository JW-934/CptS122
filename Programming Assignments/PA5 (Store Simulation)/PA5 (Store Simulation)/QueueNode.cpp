/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA5
* Date: March 5, 2022
* Description: A grocery store simulation utilizing queues.
*/

#include "QueueNode.h"
#include "Data.h"

QueueNode::QueueNode(const int newNumber, const int newServiceTime, const int newTotalTime)
{
	this->pData = new Data;
	this->pData->setNumber(newNumber);
	this->pData->setServTime(newServiceTime);
	this->pData->setTotalTime(newTotalTime);

	this->pNext = nullptr;
}

QueueNode::~QueueNode()
{
	std::cout << "In Node Destructor" << std::endl;
}

void QueueNode::setNextPtr(QueueNode* newNextPtr)
{
	this->pNext = newNextPtr;
}

QueueNode* QueueNode::getNextPtr() const
{
	return pNext;
}

Data QueueNode::getData() const
{
	return *this->pData;
}