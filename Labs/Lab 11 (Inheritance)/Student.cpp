/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 8
* Date: March 9, 2022
* Description: Implementation of a binary search tree
*/

#include "Student.h"

Student::Student()
{

}

Student::~Student()
{
	/*for (int i = 0; i < mNumCourses; ++i)
	{
		free mCourses[i];
	}*/

	delete[] mCourses;
}

// Getters
int Student::getNumCourses()
{
	return mNumCourses;
}

int Student::getNumCredits()
{
	return mNumCredits;
}

// Setters
void Student::setNumCourses(const int newNumCourses)
{
	mNumCourses = newNumCourses;
}

void Student::setNumCredits(const int newNumCredits)
{
	mNumCredits = newNumCredits;
}

void Student::addCourse(const string newName, const int newCredits, const double newGrade)
{
	Course newCourse;

	newCourse.name = newName;
	newCourse.credits = newCredits;
	newCourse.grade = newGrade;

	mCourses[mNumCourses] = newCourse;

	if (mCourses[mNumCourses].name == newName && mCourses[mNumCourses].credits == newCredits && mCourses[mNumCourses].grade == newGrade)
	{
		++mNumCourses;
	}
}