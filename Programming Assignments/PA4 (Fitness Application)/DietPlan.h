/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA4
* Date: February 16, 2022, February 20, 2022, February 23, 2022, February 24, 2022, March 1, 2022, March 4, 2022
* Description: a basic fitness application that allows the user of the application to manually edit diet and
*			   exercise plans
*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>

class DietPlan
{
public:
	// constructor with default arguments - in general, replaces the need for other constructors, exclusing copy constructors
	DietPlan(const int goalCalories, const std::string planName, std::string date);
	DietPlan();

	// copy constructor - pass-by-value
	DietPlan(const DietPlan& copy);

	// destructor
	~DietPlan(); 

	// getters/accessors
	int getCalories() const;
	std::string getName() const;
	std::string getDate() const;

	// setters/mutators
	void setCalories(const int newCalories);
	void setName(const std::string newName);
	void setDate(const std::string newDate);

	// operations
	void editGoal();
	void print();
	void clear();
	
private:
	int mgoalCalories;
	std::string mplanName;
	std::string mdate;
};

std::ostream& operator<< (std::ostream& lhs, const DietPlan& rhs);
std::istream& operator>> (std::istream& lhs, DietPlan& rhs);
std::ofstream& operator<< (std::ofstream& lhs, const DietPlan& rhs);