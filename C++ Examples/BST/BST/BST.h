#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Node.h"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

template <class T>
class BST
{
	BST(Node<T> *newProot = nullptr);
private:
	Node<T>* mpRoot;
};