/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 10
* Date: April 6, 2022
* Description: Implementation of merge sort and a BST deleteNode() template
*/

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

	Node<T>* getPleft();
	Node<T>* getPright();
	T getData();
private:
	T mData;
	Node<T>* mpLeft;
	Node<T>* mpRight;
};

template <class T>
Node<T>::Node(const T& newData)
{
	mData = newData;
	mpLeft = nullptr;
	mpRight = nullptr;
}

template <class T>
Node<T>* Node<T>::getPleft()
{
	return mpLeft;
}

template <class T>
Node<T>* Node<T>::getPright()
{
	return mpRight;
}

template <class T>
T Node<T>::getData()
{
	return mData;
}