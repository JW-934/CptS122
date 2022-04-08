#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Employee is a base class
class Employee
{
	// We will not use qualifiers (i.e. like const) in all possible places
	// in this example to simplify a bit
public:
	Employee(const string &newName = "", const double &newPayRate = 8.55, 
		const double &newHours = 0.0);
	virtual ~Employee();

	string getName();
	double getPayRate();
	double getHours();

	void setName(const string &newName);
	void setPayRate(const double &newPayRate);
	void setHours(const double &newHours);

	// With 1 pure virtual, the entire class becomes an abstract class that cannot be instantiated
	virtual double calculatePay() = 0; // pure virtual function // override a function

protected:
	string mName;
	double mPayRate;
	double mHours;
};