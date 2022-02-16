/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 5
* Date: February 16, 2022
* Description: Basic C++ Member Functions
*/

#include "Lab 5.h"
#include <iostream>

int main()
{
	Complex c1, c2, c3;

	//testAdd();

	//testSubtract();

	promptForComplex();
	c1.read();

	//cout << c1.getReal() << " " << c1.getImaginary();
	c1.print();

	//testStreamExtractionAndRead();

	return 0;
}