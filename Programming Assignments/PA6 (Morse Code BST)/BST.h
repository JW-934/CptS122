/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA6
* Date: March 21, 2022
* Description: A binary search tree based English to morse code converter.
*/

#pragma once

#include <vector>
#include "BSTNode.h"

class BST
{
public:
	// Constructors
	BST(BSTNode* newRoot = nullptr);

	// Destructor
	~BST();

	// Setters
	void setRoot(BSTNode* newRoot);

	// Getters
	BSTNode* getRoot();

	// Operations
	void insertNode(std::string& newData);
	void insertNode(BSTNode* pTree, std::string& newData);

	void inOrderTraversal(); // This one will actually be called
	void inOrderTraversal(BSTNode* pTree);

	void preOrderTraversal(); // This one will actually be called
	void preOrderTraversal(BSTNode* pTree);

	void postOrderTraversal(); // This one will actually be called
	void postOrderTraversal(BSTNode* pTree);

	void inOrderTraversal(std::vector<std::string>& names); // This one will actually be called
	void inOrderTraversal(BSTNode* pTree, std::vector<std::string>& names);	// For sorting the strings in the vector

	bool isEmpty();
private:
	BSTNode* mroot;

	void destroyTree(BSTNode* pTree);
};

