/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA6
* Date: March 21, 2022, March 23, 2022, March 24, 2022
* Description: A binary search tree based English to morse code converter.
*/

#pragma once

#include <vector>
#include "BSTNode.h"
#include <string>
#include <fstream>
#include <ctype.h>

class BST
{
public:
	// Constructors
	//BST(BSTNode* newRoot = nullptr);
	BST();

	// Destructor
	~BST();

	// Setters
	void setRoot(BSTNode* newRoot);

	// Getters
	BSTNode* getRoot();

	// Operations
	void insertNode(char newChar, std::string& newData);
	void insertNode(BSTNode* pTree, char newChar, std::string& newData);

	void inOrderTraversal(); // This one will actually be called
	void inOrderTraversal(BSTNode* pTree);

	void preOrderTraversal(); // This one will actually be called
	void preOrderTraversal(BSTNode* pTree);

	void postOrderTraversal(); // This one will actually be called
	void postOrderTraversal(BSTNode* pTree);

	void inOrderTraversal(std::vector<std::string>& names); // This one will actually be called
	void inOrderTraversal(BSTNode* pTree, std::vector<std::string>& names);	// For sorting the strings in the vector

	bool isEmpty();

	std::string morseSearch(char& search); // Call this one
	std::string morseSearch(char& search, BSTNode* pTree);

	std::string strToMorse(const std::string& input);
private:
	BSTNode* mroot;

	void destroyTree(BSTNode* pTree);
};

std::string getInput();
