/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Date: February 7, 2022, February 9, 2022, February 11, 2022
* Description: Introduction to C++
*/

#include "Rectangle.hpp"

int add(int n1, int n2)
{
	return n1 + n2;
}

double add(double n1, double n2)
{
	return n1 + n2;
}

std::string add(std::string n1, std::string n2)
{
	return n1 + n2; // + can concatenate in C++
}

//// constructor - member function - methods
//// special member function
//Rectangle::Rectangle()
//{
//	mLength = 0.0;
//	mWidth = 0.0;
//}

//Rectangle::Rectangle(double newLength, double newWidth)
//{
//	mLength = newLength;
//	mWidth = newWidth;
//}

Rectangle::Rectangle(double newLength, double newWidth)
{
	// validate data first
	/*mLength = newLength;
	mWidth = newWidth;*/

	if (newLength >= 0.0)
	{
		mLength = newLength;
	}
	else
	{
		mLength = 0.0;
	}

	if (newWidth >= 0.0)
	{
		mWidth = newWidth;
	}
	else
	{
		mWidth = 0.0;
	}
}

// destructor
Rectangle::~Rectangle()
{
	std::cout << "Inside Rectangle destructor!" << std::endl;
}

// error checking possible in setters and constructors

// getters/accessors
double Rectangle::getLength() const		// This const means the function cannot change any data members of the class
{
	return mLength;
}
double Rectangle::getWidth() const
{
	return mWidth;
}

// setters/mutators
void Rectangle::setLength(const double newLength)
{
	if (newLength >= 0.0)
	{
		mLength = newLength;
	}
	else
	{
		mLength = 0.0;
	}
}
void Rectangle::setWidth(const double newWidth)
{
	if (newWidth >= 0.0)
	{
		mWidth = newWidth;
	}
	else
	{
		mWidth = 0.0;
	}
}