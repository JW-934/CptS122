/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA6
* Date: March 21, 2022, March 23, 2022
* Description: A binary search tree based English to morse code converter.
*/

#include "BST.h"

// Constructors
//BST::BST(BSTNode* newRoot)
//{
//	mroot = newRoot;
//}

BST::BST()
{
	std::ifstream tableFile;
	char newChar, space;
	std::string newMorse;

	tableFile.open("MorseTable.txt", std::ios::in);

	//std::getline(infile, inputStr);
	
	// Get first character and morse code and set as root
	tableFile >> newChar >> space >> newMorse;
	
	mroot = new BSTNode(newChar, newMorse);
	
	while (!tableFile.eof())
	{
		//tableFile >> newChar >> space >> newMorse;
		tableFile >> newChar >> newMorse;

		insertNode(newChar, newMorse);
	}
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
void BST::insertNode(char newChar, std::string& newData)
{
	insertNode(mroot, newChar, newData);
}

void BST::insertNode(BSTNode* pTree, char newChar, std::string& newData)
{
	if (pTree == nullptr)
	{
		mroot = new BSTNode(newChar, newData);
	}
	else
	{
		if (pTree->mchar < newChar)
		{
			if (pTree->mpRight == nullptr) // need to insert
			{
				pTree->mpRight = new BSTNode(newChar, newData);
			}
			else // continuing down right tree
			{
				insertNode(pTree->mpRight, newChar, newData);
			}
		}
		else if (newChar < pTree->mchar)
		{
			// left side of tree
			if (pTree->mpLeft == nullptr)
			{
				pTree->mpLeft = new BSTNode(newChar, newData);
			}
			else
			{

				insertNode(pTree->mpLeft, newChar, newData);
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
		std::cout << pTree->getChar() << " " << pTree->getData() << " ";
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
		std::cout << pTree->getChar() << " " << pTree->getData() << " ";
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
		std::cout << pTree->getChar() << " " << pTree->getData() << " ";
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

std::string BST::morseSearch(char search)
{
	return morseSearch(search, mroot);
}

std::string BST::morseSearch(char search, BSTNode* pTree)
{
	if (pTree != nullptr)
	{
		if (pTree->getChar() == search)
		{
			return pTree->getData();
		}
		else if (pTree->getChar() < search)
		{
			morseSearch(search, pTree->getpRight());
		}
		else if (pTree->getChar() > search)
		{
			morseSearch(search, pTree->getpLeft());
		}

		//morseSearch(search, pTree->getpLeft());
		//morseSearch(search, pTree->getpRight());
		//std::cout << pTree->getChar() << " " << pTree->getData() << " ";
	}
}

// Private functions
void BST::destroyTree(BSTNode* pTree)
{
	if (pTree != nullptr)
	{
		destroyTree(pTree->getpLeft());
		destroyTree(pTree->getpRight());
		std::cout << "Node containing: " << pTree->getChar() << " " << pTree->getData() << " has been deleted." << std::endl;
		delete pTree;
	}
}