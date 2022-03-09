/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 8
* Date: March 9, 2022
* Description: Implementation of a binary search tree
*/

#include "BSTNode.h"

// Constructors
BSTNode::BSTNode(std::string newData)
{
	mdata = newData;

	mpLeft = nullptr;
	mpRight = nullptr;
}

// Destructor
BSTNode::~BSTNode()
{

}

// Setters
void BSTNode::setData(const std::string& newData)
{
	mdata = newData;
}

void BSTNode::setpLeft(BSTNode* const newLeft)
{
	mpLeft = newLeft;
}

void BSTNode::setpRight(BSTNode* const newRight)
{
	mpRight = newRight;
}

// Getters
std::string BSTNode::getData() const
{
	return mdata;
}

BSTNode* BSTNode::getpLeft() const
{
	return mpLeft;
}

BSTNode* BSTNode::getpRight() const
{
	return mpRight;
}

// Non member functions
ostream& operator<<(ostream& lhs, const BSTNode& rhs);
{
	lhs << rhs.getData();

	return lhs;
}