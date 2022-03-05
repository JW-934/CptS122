/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA4
* Date: February 16, 2022, February 20, 2022, February 23, 2022, February 24, 2022, March 1, 2022, March 4, 2022
* Description: a basic fitness application that allows the user of the application to manually edit diet and
*			   exercise plans
*/

#include "DietPlan.h"

// constructor with default arguments - in general, replaces the need for other constructors, excluding copy constructors

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

DietPlan::DietPlan()
{
	mplanName = "";
	mgoalCalories = 0;
	mdate = "";
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
	std::string newName, newDate;
	int newCals = -1;

	std::cout << "Enter a new plan name > ";
	std::cin >> newName;
	//std::cin >> discard;
	putchar('\n');

	do
	{
		std::cout << "Enter a new calorie goal > ";
		std::cin >> newCals;
		//std::cin >> discard;
		putchar('\n');
	} while (newCals < 0);

	std::cout << "Enter a new date (mm/dd/yyyy) > ";
	std::cin >> newDate;
	//std::cin >> discard;
	putchar('\n');

	this->mplanName = newName;
	this->mgoalCalories = newCals;
	this->mdate = newDate;
}

void DietPlan::print()
{
	std::cout << mplanName << " " << mgoalCalories << " Calories" << mdate << std::endl;
}

void DietPlan::clear()
{
	mplanName = "";
	mgoalCalories = 0;
	mdate = "";
}

// non member functions
std::ostream& operator<< (std::ostream& lhs, const DietPlan& rhs)
{
	lhs << rhs.getName() << " " << rhs.getCalories() << " " << rhs.getDate();

	return lhs;
}

std::ofstream& operator<< (std::ofstream& lhs, const DietPlan& rhs)
{
	lhs << rhs.getName() << std::endl << rhs.getCalories() << std::endl << rhs.getDate() << std::endl;

	return lhs;
}

std::istream& operator>> (std::istream& lhs, DietPlan& rhs)
{
	std::string line;

	std::getline(lhs, line);
	rhs.setName(line);
	std::getline(lhs, line);
	rhs.setCalories(atoi(line.c_str()));
	std::getline(lhs, line);
	rhs.setDate(line);

	std::getline(lhs, line);

	return lhs;
}

