/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 8
* Date: March 9, 2022
* Description: Implementation of a binary search tree
*/

#pragma once

#include "Person.h"

class TestPerson : public Person
{
public:
	TestPerson(const string newName = "", const int newAge = 0, const string newGender = "", const double newHeight = 0.0) : Person(newName, newAge, newGender, newHeight)
	{

	}

	~TestPerson();

	
private:
};

// Test Functions
// Getters
void testGetName();
void testGetAge();
void testGetGender();
void testGetHeight();

// Setters
void testSetName();
void testSetAge();
void testSetGender();
void testSetHeight();

// Operators
void testAssignment();