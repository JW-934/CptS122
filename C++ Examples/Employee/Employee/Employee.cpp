#include "Employee.h"

Employee::Employee(const string &newName, const double &newPayRate, const double &newHours)
{
	cout << "Inside Employee Constructor!!" << endl;

	mName = newName;
	mPayRate = newPayRate;
	mHours = newHours;
}

Employee::~Employee()
{
	cout << "Inside Employee Destructor" << endl;
}

string Employee::getName()
{
	return mName;
}

double Employee::getPayRate()
{
	return mPayRate;
}

double Employee::getHours()
{
	return mHours;
}

void Employee::setName(const string &newName)
{
	mName = newName;
}

void Employee::setPayRate(const double &newPayRate)
{
	mPayRate = newPayRate;
}

void Employee::setHours(const double &newHours)
{
	mHours = newHours;
}

double Employee::calculatePay()
{
	return mHours * mPayRate;
}