/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 12
* Date: April 13, 2022
* Description: Inheritance and Containers
*/

#pragma once

template< class NODETYPE > class List;  // forward declaration

template<class NODETYPE>

class ListNode
{
	friend class List<NODETYPE>; // make List a friend
public:
	ListNode(const NODETYPE& newData);  // copy constructor
	NODETYPE getData() const;      // return data in the node
private:
	NODETYPE data;                 // data
	ListNode<NODETYPE>* nextPtr; // next node in the list
};

template<class NODETYPE>
ListNode<NODETYPE>::ListNode(const NODETYPE& newData)  // copy constructor
{
	data = newData;
	nextPtr = nullptr;
}

template<class NODETYPE>
NODETYPE ListNode<NODETYPE>::getData() const      // return data in the node
{
	return data;
}