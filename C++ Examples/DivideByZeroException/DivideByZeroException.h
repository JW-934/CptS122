#pragma once

#include <iostream>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::runtime_error;

class DivideByZeroException : public runtime_error
{
public:
	// use runtime_error constructor to set message
	DivideByZeroException() : runtime_error("Dividing by 0!")
	{

	}
};