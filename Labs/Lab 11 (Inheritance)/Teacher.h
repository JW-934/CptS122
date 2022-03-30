/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 8
* Date: March 9, 2022
* Description: Implementation of a binary search tree
*/

#pragma once

#include "Person.h"

class Teacher : public Person
{
public:

private:
	Course mCourses[];
	int mNumCourses;
	int mNumCredits;
};

typedef struct course
{
	string name;
	int credits;
	double avgGrade;
}Course;