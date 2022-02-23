/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 6
* Date: February 23, 2022
* Description: Queues
*/

#include "QueueNode.h"

QueueNode::QueueNode(std::string newData)
{
	mdata = newData;
	mpNext = nullptr;
}

std::string QueueNode::getData()
{
	return mdata;
}

void QueueNode::setData(std::string newData)
{
	mdata = newData;
}

QueueNode* QueueNode::getNextPtr()
{
	return mpNext;
}