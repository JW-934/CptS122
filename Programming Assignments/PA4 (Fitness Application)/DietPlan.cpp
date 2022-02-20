/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA4
* Date: February 16, 2022, February 20, 2022
* Description: a basic fitness application that allows the user of the application to manually edit “diet” and
*			   “exercise” plans
*/

#include "DietPlan.h"

// constructor with default arguments - in general, replaces the need for other constructors, exclusing copy constructors
DietPlan::DietPlan(const int goalCalories = 0, const std::string planName = "", std::string date = "")
{
	// Validates the calorie value
	if (goalCalories > 0)
	{
		mgoalCalories = goalCalories;
	}
	else
	{
		std::cout << "Invalid Calorie Value" << std::endl;
	}
	mplanName = planName;
	mdate = date;
}

// copy constructor - pass-by-value
DietPlan::DietPlan(const DietPlan& copy)
{
	mgoalCalories = copy.mgoalCalories;
	mplanName = copy.mplanName;
	mdate = copy.mdate;
}

// destructor
DietPlan::~DietPlan()
{

}

// getters/accessors
int DietPlan::getCalories() const
{
	return mgoalCalories;
}
std::string DietPlan::getName() const
{
	return mplanName;
}
std::string DietPlan::getDate() const
{
	return mdate;
}

// setters/mutators
void DietPlan::setCalories(const int newCalories)
{
	// Validates the calorie value
	if (newCalories > 0)
	{
		mgoalCalories = newCalories;
	}
	else
	{
		std::cout << "Invalid Calorie Value" << std::endl;
	}
}
void DietPlan::setName(const std::string newName)
{
	mplanName = newName;
}
void DietPlan::setDate(const std::string newDate)
{
	mdate = newDate;
}

// operations
void DietPlan::editGoal()
{

}

// non member functions
std::ostream& operator<< (std::ostream& lhs, const DietPlan& rhs)
{
	lhs << "Name: " << rhs.getName() << "Calories: " << rhs.getCalories() << "Date: " << rhs.getDate();

	return lhs;
}