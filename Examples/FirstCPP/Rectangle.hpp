/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Date: February 7, 2022, February 9, 2022, February 11, 2022, February 14, 2022
* Description: Introduction to C++
*/

#pragma once

#include <iostream>
#include <string>

// using namespace std; terrible idea, opens up name collision possibility

using std::cout;

// overloaded functions possible in C++
// params must be different
int add(int n1, int n2);
double add(double n1, double n2);
std::string add(std::string n1, std::string n2);
void setInteger(int& newInt);

class Rectangle // make custom classes uppercase
{
public:
	// constructor - member function - methods
	// special member function
	//Rectangle(); // default constructor
	//Rectangle(double newLength, double newWidth);
	Rectangle(double newLength = 0.0, double newWidth = 0.0); // can have default arguments (only in declaration); if no parameters, uses zero

	// copy constructor
	Rectangle(const Rectangle &copy); // Rectangle(const Rectangle copy); passing in copy not the way; & is the reference operator (passing by reference not by value)

	// destructor
	~Rectangle(); // destroy the object - clean up resources like memory, streams, etc.

	// getters/accessors
	double getLength() const;
	double getWidth() const;

	// setters/mutators
	void setLength(const double newLength);
	void setWidth(const double newWidth);

	double computeArea();
private:					// private by default, only members of class can see
							// data members or attributes
	double mLength;			// the m is for member
	double mWidth;
};

Rectangle f(Rectangle r1); // passing by value
std::ostream operator<< (std::ostream& lhs, Rectangle& r1);