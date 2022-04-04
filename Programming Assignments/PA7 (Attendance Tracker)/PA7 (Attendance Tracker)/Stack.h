/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA7
* Date: March 27, 2022, April 4, 2022
* Description: This application manages attendance for a course.
*/

#pragma once

#include <iostream>
#include <string>
#include <ctype.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <class T>
class Stack
{
public:
	Stack(int newSize = 0);
	~Stack();

	bool push(T& newItem);
	bool pop(T& poppedItem);
	bool peek(T& item);

	bool isEmpty();

private:
	int mSize; 
	int mMaxSize; 
	T* mTop; 
};

template <class T>
Stack<T>::Stack(int newSize)
{
	mSize = newSize; 
	mMaxSize = 100;
	mTop = new T[100]; 
}

template <class T>
Stack<T>::~Stack()
{
	delete[] mTop; 
}

// Places the newItem at the top of the stack
template <class T>
bool Stack<T>::push(T& newItem)
{
	if (isEmpty())
	{
		mTop[0] = newItem;
		mSize = 1;

		if (mTop[0] == newItem)
		{
			return true;
		}
		else
		{
			--mSize;
			return false;
		}
	}
	else
	{
		mTop[mSize] = newItem; // not mSize + 1 because mSize will be one more than the current array index
		++mSize;

		if (mTop[mSize - 1] == newItem)
		{
			return true;
		}
		else
		{
			--mSize;
			return false;
		}
	}
}

template <class T>
bool Stack<T>::pop(T& poppedItem)
{
	if (!isEmpty())
	{
		poppedItem = mTop[mSize - 1];
		mTop[mSize - 1] = -1;
		--mSize;

		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
bool Stack<T>::peek(T& item)
{
	if (!isEmpty())
	{
		item = mTop[mSize - 1];
		return true;
	}
	else
	{
		return false;
	}
}

// Returns true if the stack is empty; false otherwise
template <class T>
bool Stack<T>::isEmpty()
{
	return mSize == 0;
}
