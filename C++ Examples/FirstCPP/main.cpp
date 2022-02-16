/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Date: February 7, 2022, February 9, 2022, February 11, 2022, February 14, 2022, February 16, 2022
* Description: Introduction to C++
*/

// #include <iostream> // basically <stdio.h>

#include "Rectangle.hpp"

int main(void)
{
	int n1 = 0;

	setInteger(n1);

	std::cout << "n1: " << n1 << std::endl;

	Rectangle r1, r2(1, 3), r3(5); // instantiated a Rectangle, variables initialized because constructor exists
								   // for r3, 5 will be length and width will be 0, goes left to right

	f(r2);

	r1.setLength(-1);
	r2.setLength(5);

	std::cout << "Length: " << r2.getLength() << " " << "Width: " << r2.getWidth() << std::endl;

	std::cout << "area: " << r2.computeArea() << std::endl;

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