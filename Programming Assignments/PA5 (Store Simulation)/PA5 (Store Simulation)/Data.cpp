/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA5
* Date: March 5, 2022, March 10, 2022
* Description: A grocery store simulation utilizing queues.
*/

#include "Data.h"

// Constructor
Data::Data(const int newNumber, const int newServTime, const int newTotalTime)
{
	customerNumber = newNumber;
	serviceTime = newServTime;
	totalTime = newTotalTime;
}

// Getters
int Data::getNumber()
{
	return customerNumber;
}

int Data::getServTime()
{
	return serviceTime;
}

int Data::getTotalTime()
{
	return totalTime;
}

// Setters
void Data::setNumber(int newNumber) 
{
	customerNumber = newNumber;
}

void Data::setServTime(int newTime)
{
	serviceTime = newTime;
}

void Data::setTotalTime(int newTime)
{
	totalTime = newTime;
}

// Operations
void Data::clear()
{
	customerNumber = 0;
	serviceTime = 0;
	totalTime = 0;
}