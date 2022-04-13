/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 12
* Date: April 13, 2022
* Description: Inheritance and Containers
*/

#pragma once

#include <iostream>
#include "ListNode.h"

template <class NODETYPE>

class List
{
public:
	List();      // constructor
	~List();     // destructor
	void insertAtFront(const NODETYPE& newData);
	void insertAtBack(const NODETYPE& newData);
	bool removeFromFront(NODETYPE& removedData);
	bool removeFromBack(NODETYPE& removedData);
	bool isEmpty() const;
	void print() const;
private:
	ListNode<NODETYPE>* firstPtr;  // pointer to first node
	ListNode<NODETYPE>* lastPtr;   // pointer to last node

	// Utility function to allocate a new node
	ListNode<NODETYPE>* getNewNode(const NODETYPE& newData);
};

template <class NODETYPE>
List<NODETYPE>::List()      // constructor
{
	firstPtr = nullptr;
	lastPtr = nullptr;
}

template <class NODETYPE>
List<NODETYPE>::~List()     // destructor
{

}

template <class NODETYPE>
void List<NODETYPE>::insertAtFront(const NODETYPE& newData)
{
	ListNode<NODETYPE>* pMem = getNewNode(newData);
		
	pMem->nextPtr = firstPtr;
	firstPtr = pMem;
}

template <class NODETYPE>
void List<NODETYPE>::insertAtBack(const NODETYPE& newData)
{
	ListNode<NODETYPE>* pMem = getNewNode(newData);

	if (lastPtr == nullptr)
	{
		lastPtr = pMem;
		firstPtr = pMem;
	}
	else
	{
		lastPtr->nextPtr = pMem;
		lastPtr = pMem;
	}
}

template <class NODETYPE>
bool List<NODETYPE>::removeFromFront(NODETYPE& removedData)
{
	
	if (firstPtr != nullptr)
	{
		removedData = firstPtr->data;

		ListNode<NODETYPE>* delNode = firstPtr;

		firstPtr = firstPtr->nextPtr;

		delete delNode;

		if (delNode == nullptr)
		{
			return true;
		}
		else { return false; };
	}
	else { return false; }
}

template <class NODETYPE>
bool List<NODETYPE>::removeFromBack(NODETYPE& removedData)
{
	if (lastPtr != nullptr)
	{
		removedData = lastPtr->data;

		ListNode <NODETYPE>* pCur = firstPtr, * pNext = firstPtr->nextPtr;

		bool done = false;
		ListNode<NODETYPE>* delNode = lastPtr;

		while (!done && pNext != nullptr) // Sets pCur to new last node
		{
			if (pNext == lastPtr)
			{
				done = true;
			}
			else
			{
				pCur = pNext;
				pNext = pCur->nextPtr;
			}
		}

		lastPtr = pCur;

		delete delNode;

		if (delNode == nullptr)
		{
			return true;
		}
		else { return false; };
	}
	else { return false; }
}

template <class NODETYPE>
bool List<NODETYPE>::isEmpty() const
{
	if (firstPtr == nullptr && lastPtr == nullptr)
	{
		return true;
	}
	else { return false; };
}

template <class NODETYPE>
void List<NODETYPE>::print() const
{
	ListNode <NODETYPE>* pCur = firstPtr;

	if (pCur != nullptr)
	{
		while (pCur != nullptr)
		{
			std::cout << pCur->data << std::endl;
			pCur = pCur->nextPtr;
		}
	}
}

// Utility function to allocate a new node
template <class NODETYPE>
ListNode<NODETYPE>* List<NODETYPE>::getNewNode(const NODETYPE& newData)
{
	return new ListNode<NODETYPE>(newData);
}