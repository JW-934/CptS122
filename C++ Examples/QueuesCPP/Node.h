#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

template <class T>
class Node
{
public:
	Node(std::string newPrintJob);

	~Node();

	void setNextPtr(Node* newNextPtr);

	Node* getNextPtr() const;

	std::string getData() const;

private:
	std::string mPJ;
	Node* mpNext;
};