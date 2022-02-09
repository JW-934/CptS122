/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Date: February 7, 2022, February 9, 2022
* Description: Introduction to C++
*/

// #include <iostream> // basically <stdio.h>

#include "Rectangle.hpp"

int main(void)
{
	Rectangle r1; // instantiated a Rectangle

	r1.

	int n = 10;

	cout << "It's about time we're in C++." << std::endl;
	std::cout << n << std::endl; // no &d needed

	int int_result = 0; // declaring vars right before needed is standard in C++
	int_result = add(5, 7);
	std::cout << int_result << std::endl;
	
	double double_result = 0;
	double_result = add(5.0, 7.0); // omitting the .0 would be an issue, must explicitly cast
	std::cout << double_result << std::endl;

	std::string string_result = "";
	string_result = add("cat", "dog"); // these strings are not objects, pretty much char*s, later get converted into standard strings
	std::cout << string_result << std::endl;

	return 0;
}