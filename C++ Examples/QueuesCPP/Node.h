#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

template <class T>
class Node
{
public:
	Node(const T &newPrintJob);
	~Node();

	void setNextPtr(Node<T>* newNextPtr);
	Node<T>* getNextPtr() const;

	T getData() const;

private:
	T mPJ;
	Node<T>* mpNext;
};

template <class T>
Node<T>::Node(const T& newPrintJob)
{
	this->mPJ = newPrintJob; // std::string copy assignment operator
	this->mpNext = nullptr;
}

template <class T>
Node<T>::~Node()
{
	cout << "Node destructor - removing " << mPJ << endl; // destructor can still access members, memory there until end of destructor
}

template <class T>
void Node<T>::setNextPtr(Node* newNextPtr)
{
	this->mpNext = newNextPtr;
}

template <class T>
Node<T>* Node<T>::getNextPtr() const
{
	return mpNext;
}
template <class T>
T Node<T>::getData() const
{
	return this->mPJ;
}