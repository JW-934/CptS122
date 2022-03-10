/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 8
* Date: March 9, 2022
* Description: Implementation of a binary search tree
*/

#pragma once

#include <string>
#include <iostream>
#include <fstream>

class BSTNode
{
public:
	friend class BST;

	// Constructors
	BSTNode(std::string newData = "");

	// Destructor
	~BSTNode();

	// Setters
	void setData(const std::string& newData);
	void setpLeft(BSTNode* const newLeft);
	void setpRight(BSTNode* const newRight);

	// Getters
	std::string getData() const;
	BSTNode* getpLeft() const;
	BSTNode* getpRight() const;

private:
	std::string mdata;

	BSTNode* mpLeft;
	BSTNode* mpRight;
};

// Non member functions
std::ostream& operator<<(std::ostream& lhs, const BSTNode& rhs);