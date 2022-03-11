#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Rational.h"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;



template <class T>
class Node
{
public:
	template <class T>
	friend class BST;

	Node(const T& newData);
	~Node();

	Node<T>* getRightPtr() const;
	Node<T>* getLeftPtr() const;
	T getData() const;

	void setRightPtr(Node<T>* const newRightPtr);
	void setLeftPtr(Node<T>* const newLeftPtr);
	void setData(const T& newData);


private:
	T mData;
	Node<T>* mpLeft;
	Node<T>* mpRight;
};

template <class T>
Node<T>::Node(const T& newData)
{
	this->mpLeft = this->mpRight = nullptr;
	this->mData = newData; // assignment operator for type T
}

template <class T>
Node<T>::~Node()
{
	cout << "Deleting: " << this->mData << endl;
	//delete this;

	if (this->mpLeft != nullptr)
	{
		delete this->mpLeft;
	}
	if (this->mpRight != nullptr)
	{
		delete this->mpRight;
	}
}

template <class T>
Node<T>* Node<T>::getRightPtr() const
{
	return this->mpRight;
}

template <class T>
Node<T>* Node<T>::getLeftPtr() const
{
	return this->mpLeft;
}

template <class T>
T Node<T>::getData() const
{
	return this->mData;
}

template <class T>
void Node<T>::setRightPtr(Node<T>* const newRightPtr)
{
	this->mpRight = newRightPtr;
}

template <class T>
void Node<T>::setLeftPtr(Node<T>* const newLeftPtr)
{
	this->mpLeft = newLeftPtr;
}

template <class T>
void Node<T>::setData(const T& newData)
{
	this->mData = newData;
}