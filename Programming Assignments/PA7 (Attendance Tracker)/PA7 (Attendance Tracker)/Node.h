/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA7
* Date: March 27, 2022, April 4, 2022, April 7, 2022
* Description: This application manages attendance for a course.
*/

#pragma once

#include "Data.h"

template <class T>
class Node
{
public:
	Node();
	Node(const T& newData);

	~Node();

	T getData() const;
	Node<T>* getPnext();

	void setData(T& newData);
	void setPnext(Node<T>* newPnext);
private:
	T mData;
	Node<T>* mpNext;
};

template <class T>
Node<T>::Node()
{
	mData = NULL;
}

template <class T>
Node<T>::Node(const T& newData)
{
	mData = newData;
}

template <class T>
Node<T>::~Node()
{

}

template <class T>
T Node<T>::getData() const
{
	return mData;
}

template <class T>
Node<T>* Node<T>::getPnext()
{
	return mpNext;
}

template <class T>
void Node<T>::setData(T& newData)
{
	mData = newData;
}

template <class T>
void Node<T>::setPnext(Node<T>* newPnext)
{
	mpNext = newPnext;
}