/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA7
* Date: March 27, 2022, April 4, 2022, April 7, 2022
* Description: This application manages attendance for a course.
*/

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Node.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::fstream;

template <class T>
class List
{
public:
	List(Node<T>* newPhead = nullptr);

	~List();

	Node<T>* getPhead() const;

	void setPhead(Node<T>* newPhead);

	void insertFront(T& newData);

	void printListRec() const;
	void printListRec(Node<T>* pList) const;

private:
	Node<T>* mpHead;
};

template <class T>
List<T>::List(Node<T>* newPhead)
{
	mpHead = newPhead;
}

template <class T>
List<T>::~List()
{

}

template <class T>
Node<T>* List<T>::getPhead() const
{
	return mpHead;
}

template <class T>
void List<T>::setPhead(Node<T>* newPhead)
{
	mpHead = newPhead;
}

template <class T>
void List<T>::insertFront(T& newData)
{
	Node<T>* pMem = new Node<T>;

	pMem->setData(newData);

	pMem->setPnext(mpHead);

	mpHead = pMem;
}

template <class T>
void List<T>::printListRec() const
{
	printListRec(mpHead);
}

template <class T>
void List<T>::printListRec(Node<T>* pList) const
{
	if (pList != nullptr)
	{
		cout << pList->getData() << endl;
		printListRec(pList->getPnext());
	}
	else
	{
		cout << endl;
	}
}