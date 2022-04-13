/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 12
* Date: April 13, 2022
* Description: Inheritance and Containers
*/

#pragma once

template< class NODETYPE >

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
	ListNode< NODETYPE >* firstPtr;  // pointer to first node
	ListNode< NODETYPE >* lastPtr;   // pointer to last node

	// Utility function to allocate a new node
	ListNode< NODETYPE >* getNewNode(const NODETYPE& newData);
};