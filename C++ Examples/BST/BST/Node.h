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
public:
	Node(const T& newData);

	T mData;
	Node<T>* mpLeft;
	Node<T>* mpRight;
private:
	T mData;
	Node<T>* mpLeft;
	Node<T>* mpRight;
};

template <class T>
Node<T>::Node(const T& newData)
{
	this->mpLeft = this->mpRight = nullptr;
	this->mData = newData; // assignment operator for type T
}