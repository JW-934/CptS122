#include "Node.h"

Node::Node(std::string newPrintJob)
{
	this->mPJ = newPrintJob; // std::string copy assignment operator
	this->mpNext = nullptr;
}

void Node::setNextPtr(Node* newNextPtr)
{
	this->mpNext = newNextPtr;
}