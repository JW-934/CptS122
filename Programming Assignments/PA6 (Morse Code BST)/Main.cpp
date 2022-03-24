/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA6
* Date: March 21, 2022, March 23, 2022, March 24, 2022
* Description: A binary search tree based English to morse code converter.
*/

#include <iostream>
#include <string>
#include <fstream>

#include "BST.h"

int main()
{
	std::ifstream convertFile, tableFile;
	
	BST table;
	char d = 'D';

	//table.inOrderTraversal();

	//std::cout << table.morseSearch(d);

	std::cout << table.strToMorse(getInput()) << std::endl;
	
	return 0;
}