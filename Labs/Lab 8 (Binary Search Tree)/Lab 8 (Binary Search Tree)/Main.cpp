/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 8
* Date: March 9, 2022
* Description: Implementation of a binary search tree
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "BST.h"

int main()
{
	BST t1;
	std::string s1 = "10", s2 = "20", s3 = "30", s4 = "40", s5 = "50", s6 = "60", s7 = "70", s8 = "80", s9 = "90";

	// BST Operation Testing /////////////////////////////////////////////////////////////////////////////////////////////
	
	// I used integers here because I wanted to compare against the example tree in the lab assignment but
	// comparing ints through strings is weird so I just went by tens and wrote down their associated example
	// values

	/*t1.insertNode(s5);
	t1.insertNode(s3);
	t1.insertNode(s8);
	t1.insertNode(s1);
	t1.insertNode(s4);
	t1.insertNode(s6);
	t1.insertNode(s9);
	t1.insertNode(s2);
	t1.insertNode(s7);

	std::cout << "In Order Traversal: ";
	t1.inOrderTraversal();

	std::cout << "Pre Order Traversal: ";
	t1.preOrderTraversal();

	std::cout << "Post Order Traversal: ";
	t1.postOrderTraversal();*/

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Task 3: String sorting application /////////////////////////////////////////////////////////////////////////////////////

	std::ifstream nameFile;
	char currStr[50];
	BST t2;

	// This should all still work with actual names in the Names.txt file, I just have strings in there
	// that are easy to recognize as sorted or not right now.
	nameFile.open("Names.txt", std::ios::in);

	std::vector<std::string> names;
	
	while (!nameFile.eof())
	{
		nameFile.getline(currStr, 50);
		names.push_back(currStr);
	}
	std::cout << "presort vector : ";
	for (int i = 0; i < names.size(); ++i)
	{
		t2.insertNode(names.at(i));
		std::cout << names.at(i);
	}

	names.clear();

	t2.inOrderTraversal(names);

	std::cout << std::endl << "postsort vector : ";
	for (int j = 0; j < names.size(); ++j)
	{
		std::cout << names.at(j);
	}
	std::cout << std::endl;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	return 0;
}