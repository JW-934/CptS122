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
	BST(Node<T>* newProot = nullptr);

	void insert(const T& newData);

private:
	Node<T>* mpRoot;

	void insert(Node<T> *pTree, const T& newData);
};

template <class T>
BST<T>::BST(Node<T>* newProot)
{
	this->mpRoot = newProot; // pointer assignment
}

template <class T>
void BST<T>::insert(const T& newData)
{
	insert(this->mpRoot, newData);
}

template <class T>
void BST<T>::insert(Node<T>* pTree, const T& newData)
{
	if (pTree == nullptr) // base case - empty tree
	{
//pTree = new
		this->mpRoot = new Node<T>(newData); // we'll implement a Node constructor Monday, 3/7
	}
}
