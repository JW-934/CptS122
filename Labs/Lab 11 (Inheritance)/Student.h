/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 8
* Date: March 9, 2022
* Description: Implementation of a binary search tree
*/

#pragma once

#include "Person.h"

class Student : public Person
{
public:
	Student();

	~Student();
	
	// Getters
	int getNumCourses();
	int getNumCredits();

	// Setters
	void setNumCourses(const int newNumCourses);
	void setNumCredits(const int newNumCredits);

	// Operations
	void addCourse(const string newName, const int newCredits, const double newGrade);

private:
	int mNumCourses;
	int mNumCredits;

	Course mCourses[];
};

typedef struct course
{
	string name;
	int credits;
	double grade;
}Course;