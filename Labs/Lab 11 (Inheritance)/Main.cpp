/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 11
* Date: March 30, 2022
* Description: Implementation of inheritance
*/

#include "TestPerson.h"

int main()
{
	// Getter Tests
	testGetName();
	testGetAge();
	testGetGender();
	testGetHeight();

	// Setter Tests
	testSetName();
	testSetAge();
	testSetGender();
	testSetHeight();

	// Operator Tests
	testAssignment();

	return 0;
}