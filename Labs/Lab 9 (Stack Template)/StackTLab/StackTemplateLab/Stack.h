// This file contains a stack class template. The underlying data structure for the 
// stack is an array allocated from the heap.

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

	bool push(T &newItem); 
	bool pop(T &poppedItem);
	bool peek(T &item);

	bool isEmpty();

	int postFixEval(std::string postFix);

private:
	int mSize; // represents the current number of items in the stack
	int mMaxSize; // must not exceed the max size of our allocated array
	T *mTop; // will point to contigous memory on the heap (an array)
};

template <class T>
Stack<T>::Stack(int newSize)
{
	mSize = newSize; // this can also be used as the index to the top of the stack
	mMaxSize = 100;
	mTop = new T[100]; // allocating an array of 100 items of type T on the heap
}

template <class T>
Stack<T>::~Stack()
{
	delete[] mTop; // this is how we free up an array on the heap in C++
}

// Places the newItem at the top of the stack
template <class T>
bool Stack<T>::push(T &newItem)
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

// In this implementation you will apply defensive design. You must check to 
// see if the stack is empty or not before you pop. Places the popped item in 
// the parameter referred to as "poppedItem". Returns true if the item was popped; false
// otherwise.
template <class T>
bool Stack<T>::pop(T &poppedItem)
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

// In this implementation you will apply defensive design. You must check to 
// see if the stack is empty or not before you peek. Places the item at the top of the
// stack in the parameter referred to as "item". Returns true if there
// is an item at the top; false otherwise.
template <class T>
bool Stack<T>::peek(T &item)
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

template <class T>
int Stack<T>::postFixEval(string postFix)
{
	if (postFix.empty())
	{
		cout << "Empty input string." << endl;

		return -69;
	}
	else
	{
		int index = 0, s1, s2, intV;
		bool empty = false;
		char c, e, o, v, pop1, pop2;

		while (!empty)
		{
			// Moves over whitespace and gets character of string
			do
			{
				c = postFix.at(index);
				++index;
			} while (c == ' ');
			
			// Checks if at end of string
			if (postFix[index] == '\0')
			{
				empty = true;
			}

			if (c == '=')
			{
				if (isEmpty())
				{
					cout << "Postfix expression malformed." << endl;
					return -69;
				}
				else if (mSize > 1)
				{
					cout << "Postfix expression malformed." << endl;
					return -69;
				}
				else if (mSize == 1)
				{
					e = mTop[0];
					return e;
				}
			}

			if (isdigit(c))
			{
				push(c);
			}

			if (c == '+' || c == '-' || c == '/' || c == '*')
			{
				o = c;

				if (mSize < 2)
				{
					cout << "Postfix expression malformed." << endl;
					return -69;
				}
				else
				{
					pop(pop2);
					pop(pop1);

					s1 = atoi(&pop1);
					s2 = atoi(&pop2);

					if (o == '+')
					{
						intV = s1 + s2;
					}
					else if (o == '-')
					{
						intV = s1 - s2;
					}
					else if (o == '/')
					{
						intV = s1 / s2;
					}
					else
					{
						intV = s1 * s2;
					}

					// Converts from integer to char to push
					v = intV - '0';

					push(v);
				}
			}
		}
	}
}