#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Node.h"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

template <class T>
class BST
{
public:
	BST(Node<T> *newProot = nullptr);

	void insert(const T &newData);

private:
	Node<T>* mpRoot;

	void insert(Node<T> *pTree, const T& newData); // This will be called recursively
};

template <class T>
BST<T>::BST(Node<T>* newProot)
{
	this->mpRoot = newProot; // pointer assignment
}

template <class T>
void BST<T>::insert(const T& newData)	// Public one
{
	insert(this->mpRoot, newData);
}

template <class T>
void BST<T>::insert(Node<T> *pTree, const T& newData)	// Private one, recursive
{
	if (pTree == nullptr) // base case
	{
		//pTree = new
		this->mpRoot = new Node<T>(newData);		// invokes constructor, needs <T>
	}
}