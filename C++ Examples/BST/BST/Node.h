#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

template <class T>
class Node
{
private:
	T mData;
	Node<T>* mpLeft;
	Node<T>* mpRight;
};