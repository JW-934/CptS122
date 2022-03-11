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

	~BST();

	void insert(const T& newData);
	void inorderTraversal();



private:
	Node<T>* mpRoot;

	void insert(Node<T> *pTree, const T& newData);
	void inorderTraversal(Node<T>* pTree);
	void destroyTree(Node<T>* pTree);
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
	else
	{
		if (pTree->mData < newData)
		{
			if (pTree->mpRight == nullptr)
			{
				// we now need to insert the node
				pTree->mpRight = new Node<T>(newData);
				//pTree->setRightPtr(new Node<T>(newData));
			}
			else // we have to continue to progress down the right subtree
			{
				// recursive step
				insert(pTree->mpRight, newData);
			}
		}
		else if (newData < pTree->mData)
		{
			// left side of tree
			if (pTree->mpLeft == nullptr)
			{
				pTree->mpLeft = new Node<T>(newData);
				//pTree->setLeftPtr(new Node<T>(newData));
			}
			else
			{
				// recursive step down the left subtree
				insert(pTree->mpLeft, newData);
			}
		}
		else
		{
			// duplicates
			cout << "duplicate: " << newData << endl;
		}
	}
}

template<class T>
void BST<T>::inorderTraversal()
{
	inorderTraversal(this->mpRoot);
}

template<class T>
void BST<T>::inorderTraversal(Node<T>* pTree)
{
	// left, process data, right

	if (pTree != nullptr)
	{
		inorderTraversal(pTree->getLeftPtr());
		cout << pTree->getData() << endl;
		inorderTraversal(pTree->getRightPtr());
	}
}

template <class T>
BST<T>::~BST ()
{
	this->destroyTree(this->mpRoot);
}

template <class T>
void BST<T>::destroyTree(Node<T>* pTree)
{
	// postorder traversal through tree to delete each node
	// l, r, process
	/*if (pTree != nullptr)
	{
		destroyTree(pTree->mpLeft);
		destroyTree(pTree->mpRight);
		delete pTree;
	}*/
	if (this->mpRoot != nullptr)
	{
		delete this->mpRoot;
	}
}