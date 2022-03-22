/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA6
* Date: March 21, 2022
* Description: A binary search tree based English to morse code converter.
*/

#include <iostream>
#include <string>
#include <fstream>

#include "BST.h"

int main()
{
	std::string inputStr;
	
	std::ifstream infile;
	infile.open("Convert.txt", std::ios::in);

	if (infile.is_open()) // infile opened
	{
		std::getline(infile, inputStr); // in progress


	}
	else // infile not opened
	{
		std::cout << "Input file could not be opened!" << std::endl;
	}
	return 0;
}