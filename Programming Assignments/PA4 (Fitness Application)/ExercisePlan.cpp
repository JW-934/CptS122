/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA4
* Date: February 16, 2022, February 20, 2022, February 23, 2022, February 24, 2022
* Description: a basic fitness application that allows the user of the application to manually edit diet and
*			   exercise plans
*/

#include "ExercisePlan.h"

// constructor with default arguments - in general, replaces the need for other constructors, exclusing copy constructors
ExercisePlan::ExercisePlan(const int goalSteps = 0, const std::string planName = "", std::string date = "")
{
	// Validates the step value
	if (goalSteps > 0)
	{
		mgoalSteps = goalSteps;
	}
	else
	{
		std::cout << "Invalid Step Value" << std::endl;
	}
	mplanName = planName;
	mdate = date;
}

ExercisePlan::ExercisePlan()
{
	mplanName = "";
	mgoalSteps = 0;
	mdate = "";
}

// copy constructor - pass-by-value
ExercisePlan::ExercisePlan(const ExercisePlan& copy)
{
	mgoalSteps = copy.mgoalSteps;
	mplanName = copy.mplanName;
	mdate = copy.mdate;
}

// destructor
ExercisePlan::~ExercisePlan()
{

}

// getters/accessors
int ExercisePlan::getSteps() const
{
	return mgoalSteps;
}
std::string ExercisePlan::getName() const
{
	return mplanName;
}
std::string ExercisePlan::getDate() const
{
	return mdate;
}

// setters/mutators
void ExercisePlan::setSteps(const int newSteps)
{
	// Validates the step value
	if (newSteps > 0)
	{
		mgoalSteps = newSteps;
	}
	else
	{
		std::cout << "Invalid Step Value" << std::endl;
	}
}
void ExercisePlan::setName(const std::string newName)
{
	mplanName = newName;
}
void ExercisePlan::setDate(const std::string newDate)
{
	mdate = newDate;
}

// operations
void ExercisePlan::editGoal()
{
	std::string newName, newDate;
	int newSteps = -1;

	std::cout << "Enter a new plan name > ";
	std::cin >> newName;
	putchar('\n');

	do
	{
		std::cout << "Enter a new step goal > ";
		std::cin >> newSteps;
		putchar('\n');
	} while (newSteps < 0);

	std::cout << "Enter a new date (mm/dd/yyyy) > ";
	std::cin >> newDate;
	putchar('\n');

	mplanName = newName;
	mgoalSteps = newSteps;
	mdate = newDate;
}

void ExercisePlan::print()
{
	std::cout << mplanName << " " << mgoalSteps << " Steps" << mdate << std::endl;
}

void ExercisePlan::clear()
{
	mplanName = "";
	mgoalSteps = 0;
	mdate = "";
}

// non member functions
std::ostream& operator<< (std::ostream& lhs, const ExercisePlan& rhs)
{
	lhs << rhs.getName() << " " << rhs.getSteps() << " " << rhs.getDate();

	return lhs;
}

std::istream& operator>> (std::istream& lhs, ExercisePlan& rhs)
{
	std::string line;

	std::getline(lhs, line);
	rhs.setName(line);
	std::getline(lhs, line);
	rhs.setSteps(atoi(line.c_str()));
	std::getline(lhs, line);
	rhs.setDate(line);

	std::getline(lhs, line);

	return lhs;
}