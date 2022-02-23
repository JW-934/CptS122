/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 6
* Date: February 23, 2022
* Description: Queues
*/

#pragma once

#include <iostream>

class QueueNode
{
public:
	QueueNode(std::string newData);

	std::string getData();

	void setData(std::string newData);
	void setNextPtr(QueueNode* newNextPtr);

	QueueNode* getNextPtr();

private:
	std::string mdata;
	QueueNode* mpNext;
};

