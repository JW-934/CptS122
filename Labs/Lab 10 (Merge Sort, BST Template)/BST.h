/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 10
* Date: April 6, 2022
* Description: Implementation of merge sort and a BST deleteNode() template
*/

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

	void deleteNode(T& search);

	void inOrderTraversal();

private:
	Node<T>* mpRoot;

	void insert(Node<T>* pTree, const T& newData);

	void deleteNode(T& search, Node<T>* pTree);

	void inOrderTraversal(Node<T>* pTree);
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
		this->mpRoot = new Node<T>(newData); 
	}
}

template <class T>
void BST<T>::deleteNode(T& search)
{
	deleteNode(search, mpRoot);
}

template <class T> 
void BST<T>::deleteNode(T& search, Node<T>* pTree)
{
	if (pTree != nullptr)
	{
		if (pTree->getData() == search)
		{
			// Node found, need to delete



			return;
		}
		else if (pTree->getData() < search)
		{
			return deleteNode(search, pTree->getPright());
		}
		else if (pTree->getData() > search)
		{
			return deleteNode(search, pTree->getPleft());
		}
	}
}

template <class T>
void BST<T>::inOrderTraversal()
{
	inOrderTraversal(mpRoot);
	std::cout << std::endl;
}

template <class T>
void BST<T>::inOrderTraversal(Node<T>* pTree)
{
	if (pTree != nullptr)
	{
		inOrderTraversal(pTree->getPleft());
		std::cout << pTree->getData() << " " << pTree->getData() << " ";
		inOrderTraversal(pTree->getPright());
	}
}