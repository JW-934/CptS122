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
}

void BST::inOrderTraversal(BSTNode* pTree)
{
	if (pTree != nullptr) 
	{
		inOrderTraversal(pTree->getpLeft());
		std::cout << pTree->getData() << std::endl;
		inOrderTraversal(pTree->getpRight());
	}
}

void BST::preOrderTraversal()
{
	preOrderTraversal(mroot);
}

void BST::preOrderTraversal(BSTNode* pTree)
{
	if (pTree != nullptr)
	{
		std::cout << pTree->getData() << std::endl;
		inOrderTraversal(pTree->getpLeft());
		inOrderTraversal(pTree->getpRight());
	}
}

void BST::postOrderTraversal()
{
	postOrderTraversal(mroot);
}

void BST::postOrderTraversal(BSTNode* pTree)
{
	if (pTree != nullptr)
	{
		postOrderTraversal(pTree->getpLeft());
		postOrderTraversal(pTree->getpRight());
		std::cout << pTree->getData() << std::endl;
	}
}

bool BST::isEmpty()
{
	return mroot == nullptr;
}

// Private functions
void BST::destroyTree(BSTNode* pTree)
{
	if (pTree != nullptr)
	{
		postOrderTraversal(pTree->getpLeft());
		postOrderTraversal(pTree->getpRight());
		std::cout << "Node containing: " << pTree->getData() << " has been deleted." << std::endl;
		delete pTree;
	}
}