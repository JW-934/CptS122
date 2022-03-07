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
	void inorderTraversal();


private:
	Node<T>* mpRoot;

	void insert(Node<T> *pTree, const T& newData); // This will be called recursively
	void inorderTraversal(Node<T>* pTree);
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
	if (pTree == nullptr) // base case - empty tree
	{
		//pTree = new
		this->mpRoot = new Node<T>(newData);		// invokes constructor, needs <T>
	}
	else
	{
		if (newData > pTree->mData) // going down right side; need overloaded inequality operators for type T
		{
			if (pTree->mpRight == nullptr)
			{
				// now need to insert the node
				pTree->mpRight = new Node<T>(newData);
			}
			else // have to continue to progress down the tree
			{
				// recursive step
				insert(pTree->mpRight, newData);
			}
		}
		else if (newData < pTree->mData) // going down left side
		{
			if (pTree->mpLeft == nullptr)
			{
				pTree->mpLeft = new Node<T>(newData);
			}
			else // recursive step
			{
				insert(pTree->mpLeft, newData);
			}
		}
		else // duplicates
		{
			cout << "duplicate: " << newData << endl; // uses stream insertion operator for type T data
		}
	}
}

template <class T>
void BST<T>::inorderTraversal()
{
	inorderTraversal(this->mpRoot);
}

template <class T>
void BST<T>::inorderTraversal(Node<T>* pTree)
{
	// order: go left, process/print data, go right, process/print data

	if (pTree != nullptr) // more nodes left to visit
	{
		inorderTraversal(pTree->mpLeft);
		cout << pTree->mData << endl;
		inorderTraversal(pTree->mpRight);
	}
}