/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA7
* Date: March 27, 2022, April 4, 2022
* Description: This application manages attendance for a course.
*/

#pragma once

template <class T>
class Node
{
	friend class List;
public:
	Node(const T& newData);

	~Node();

	T getData();

private:
	T mData;
	Node<T>* mpNext;
};

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
T Node<T>::getData()
{
	return mData;
}