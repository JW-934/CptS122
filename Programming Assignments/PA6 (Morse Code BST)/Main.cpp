/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA6
* Date: March 21, 2022, March 23, 2022
* Description: A binary search tree based English to morse code converter.
*/

#include <iostream>
#include <string>
#include <fstream>

#include "BST.h"

int main()
{
	std::ifstream convertFile, tableFile;
	//convertFile.open("Convert.txt", std::ios::in);
	
	BST table;

	table.inOrderTraversal();

	std::cout << table.morseSearch('D');
	
	return 0;
}