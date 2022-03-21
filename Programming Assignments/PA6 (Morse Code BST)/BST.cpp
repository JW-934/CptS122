/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA6
* Date: March 21, 2022
* Description: A binary search tree based English to morse code converter.
*/

#include "BST.h"

// Constructors
BST::BST(BSTNode* newRoot)
{
	mroot = newRoot;
}

// Destructor
BST::~BST()
{
	destroyTree(mroot);
}

// Setters
void BST::setRoot(BSTNode* newRoot)
{
	mroot = newRoot;
}

// Getters
BSTNode* BST::getRoot()
{
	return mroot;
}

// Operations
void BST::insertNode(std::string& newData)
{
	insertNode(mroot, newData);
}

void BST::insertNode(BSTNode* pTree, std::string& newData)
{
	if (pTree == nullptr)
	{
		mroot = new BSTNode(newData);
	}
	else
	{
		if (pTree->mdata < newData)
		{
			if (pTree->mpRight == nullptr) // need to insert
			{
				pTree->mpRight = new BSTNode(newData);
			}
			else // continuing down right tree
			{
				insertNode(pTree->mpRight, newData);
			}
		}
		else if (newData < pTree->mdata)
		{
			// left side of tree
			if (pTree->mpLeft == nullptr)
			{
				pTree->mpLeft = new BSTNode(newData);
			}
			else
			{

				insertNode(pTree->mpLeft, newData);
			}
		}
		else
		{
			// duplicates
			std::cout << "duplicate: " << newData << std::endl;
		}
	}
}

void BST::inOrderTraversal()
{
	inOrderTraversal(mroot);
	std::cout << std::endl;
}

void BST::inOrderTraversal(BSTNode* pTree)
{
	if (pTree != nullptr)
	{
		inOrderTraversal(pTree->getpLeft());
		std::cout << pTree->getData() << " ";
		inOrderTraversal(pTree->getpRight());
	}
}

void BST::preOrderTraversal()
{
	preOrderTraversal(mroot);
	std::cout << std::endl;
}

void BST::preOrderTraversal(BSTNode* pTree)
{
	if (pTree != nullptr)
	{
		std::cout << pTree->getData() << " ";
		preOrderTraversal(pTree->getpLeft());
		preOrderTraversal(pTree->getpRight());
	}
}

void BST::postOrderTraversal()
{
	postOrderTraversal(mroot);
	std::cout << std::endl;
}

void BST::postOrderTraversal(BSTNode* pTree)
{
	if (pTree != nullptr)
	{
		postOrderTraversal(pTree->getpLeft());
		postOrderTraversal(pTree->getpRight());
		std::cout << pTree->getData() << " ";
	}
}

bool BST::isEmpty()
{
	return mroot == nullptr;
}

void BST::inOrderTraversal(std::vector<std::string>& names)
{
	inOrderTraversal(mroot, names);
}

void BST::inOrderTraversal(BSTNode* pTree, std::vector<std::string>& names)
{
	if (pTree != nullptr)
	{
		inOrderTraversal(pTree->getpLeft(), names);
		names.push_back(pTree->mdata);
		inOrderTraversal(pTree->getpRight(), names);
	}
}

// Private functions
void BST::destroyTree(BSTNode* pTree)
{
	if (pTree != nullptr)
	{
		destroyTree(pTree->getpLeft());
		destroyTree(pTree->getpRight());
		std::cout << "Node containing: " << pTree->getData() << " has been deleted." << std::endl;
		delete pTree;
	}
}