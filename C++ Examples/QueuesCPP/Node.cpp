#include "Node.h"

Node::Node(std::string newPrintJob)
{
	this->mPJ = newPrintJob; // std::string copy assignment operator
	this->mpNext = nullptr;
}

Node::~Node()
{
	cout << "Node destructor - removing " << mPJ << endl; // destructor can still access members, memory there until end of destructor
}

void Node::setNextPtr(Node* newNextPtr)
{
	this->mpNext = newNextPtr;
}

Node* Node::getNextPtr() const
{
	return mpNext;
}

std::string Node::getData() const
{
	return this->mPJ;
}