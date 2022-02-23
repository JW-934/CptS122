#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

class Node
{
public:
	Node(std::string newPrintJob);

	void setNextPtr(Node* newNextPtr);

private:
	std::string mPJ;
	Node* mpNext;
};