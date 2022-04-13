/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 12
* Date: April 13, 2022
* Description: Inheritance and Containers
*/

#pragma once

#include <iostream>
#include "List.h"

template <class NODETYPE>
class Queue : private List<NODETYPE>
{
public:
	Queue();
	~Queue();

	void enqueue(NODETYPE& newData);
	NODETYPE dequeue();

private:

};

template <class NODETYPE>
Queue<NODETYPE>::Queue()
{
	
}

template <class NODETYPE>
Queue<NODETYPE>::~Queue()
{

}

template <class NODETYPE>
void Queue<NODETYPE>::enqueue(NODETYPE& newData)
{
	this->List<NODETYPE>::insertAtBack(newData);
}

template <class NODETYPE>
NODETYPE Queue<NODETYPE>::dequeue()
{
	NODETYPE data;

	this->List<NODETYPE>::removeFromFront(data);

	return data;
}