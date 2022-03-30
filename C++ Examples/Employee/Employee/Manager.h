#pragma once

#include <iostream>
#include <string>

#include "Employee.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Manager is a derived class, it's derived from Employee - need to complete the inheritance in class
class Manager : public Employee // Manager is a derived class; Employee is a base class
{
public:
	Manager(const string& newName = "", const double& newPayRate = 0.0, const double& newHours = 0, const bool& newSalariedEmployee = false) :
		Employee(newName, newPayRate, newHours)
	{
		this->mIsSalaried = newSalariedEmployee;
		cout << "Inside Manager Constructor:" << endl;
	}
	~Manager();

	// With inheritance, we should NOT have to redefine
	// many of the functions that we find in the Employee
	// class!

	double calculatePay();
private:
	bool mIsSalaried; // this attribute belongs to Manager only; Employee doesn't have it.
					  // true - salaried; false - hourly
	// Employee mE;
};