/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA6
* Date: March 21, 2022, March 23, 2022
* Description: A binary search tree based English to morse code converter.
*/

#include "BSTNode.h"

// Constructors
BSTNode::BSTNode(char newChar, std::string newData)
{
	mdata = newData;
	mchar = newChar;

	mpLeft = nullptr;
	mpRight = nullptr;
}

// Destructor
BSTNode::~BSTNode()
{

}

// Setters
void BSTNode::setChar(const char newChar)
{
	mchar = newChar;
}

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
char BSTNode::getChar() const
{
	return mchar;
}

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
std::ostream& operator<<(std::ostream& lhs, const BSTNode& rhs)
{
	lhs << rhs.getChar() << " ";
	lhs << rhs.getData();

	return lhs;
}