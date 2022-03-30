/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 8
* Date: March 9, 2022
* Description: Implementation of a binary search tree
*/

#include "TestPerson.h"

//TestPerson::TestPerson() 
//{
//
//}

TestPerson::~TestPerson()
{

}

// Test Functions
// Getters
void testGetName()
{
	cout << "********** getName() Test **********" << endl;
	
	TestPerson p1("Test Name", 0, "none", 0);
	cout << "Test Person with name: Test Name instantiated!" << endl;

	cout << "getName() returned: " << p1.getName() << endl;
	if (p1.getName() == "Test Name")
	{
		cout << "getName() test successful!" << endl;
	}
	else
	{
		cout << "getName() test failed!" << endl;
	}
	cout << endl;
}

void testGetAge()
{
	cout << "********** getAge() Test **********" << endl;

	TestPerson p1("Test Name", 42, "none", 0);
	cout << "Test Person with age: 42 instantiated!" << endl;

	cout << "getAge() returned: " << p1.getAge() << endl;
	if (p1.getAge() == 42)
	{
		cout << "getAge() test successful!" << endl;
	}
	else
	{
		cout << "getAge() test failed!" << endl;
	}
	cout << endl;
}

void testGetGender()
{
	cout << "********** getGender() Test **********" << endl;

	TestPerson p1("Test Name", 0, "Test Gender", 0);
	cout << "Test Person with gender: Test Gender instantiated!" << endl;

	cout << "getGender() returned: " << p1.getGender() << endl;
	if (p1.getGender() == "Test Gender")
	{
		cout << "getGender() test successful!" << endl;
	}
	else
	{
		cout << "getGender() test failed!" << endl;
	}
	cout << endl;
}

void testGetHeight()
{
	cout << "********** getHeight() Test **********" << endl;

	TestPerson p1("Test Height", 0, "none", 42.5);
	cout << "Test Person with height: 42.5 instantiated!" << endl;

	cout << "getHeight() returned: " << p1.getHeight() << endl;
	if (p1.getHeight() == 42.5)
	{
		cout << "getHeight() test successful!" << endl;
	}
	else
	{
		cout << "getHeight() test failed!" << endl;
	}
	cout << endl;
}


// Setters
void testSetName()
{
	cout << "********** setName() Test **********" << endl;

	TestPerson p1("Test Name", 0, "none", 0);
	cout << "Test Person with name: Test Name instantiated!" << endl;

	p1.setName("New Test Name");
	cout << "setName(\"New Test Name\") called. " << endl;
	cout << "getName() returned: " << p1.getName() << endl;

	if (p1.getName() == "New Test Name")
	{
		cout << "setName() test successful!" << endl;
	}
	else
	{
		cout << "setName() test failed!" << endl;
	}
	cout << endl;
}

void testSetAge()
{
	cout << "********** setAge() Test **********" << endl;

	TestPerson p1("Test Name", 42, "none", 0);
	cout << "Test Person with age: 42 instantiated!" << endl;

	p1.setAge(88);
	cout << "setAge(88) called. " << endl;
	cout << "getAge() returned: " << p1.getAge() << endl;

	if (p1.getAge() == 88)
	{
		cout << "setAge() test successful!" << endl;
	}
	else
	{
		cout << "setAge() test failed!" << endl;
	}
	cout << endl;
}

void testSetGender()
{
	cout << "********** setGender() Test **********" << endl;

	TestPerson p1("Test Name", 0, "Test Gender", 0);
	cout << "Test Person with gender: Test Gender instantiated!" << endl;

	p1.setGender("New Gender");
	cout << "setGender(\"New Gender\") called. " << endl;
	cout << "getGender() returned: " << p1.getGender() << endl;

	if (p1.getGender() == "New Gender")
	{
		cout << "setGender() test successful!" << endl;
	}
	else
	{
		cout << "setGender() test failed!" << endl;
	}
	cout << endl;
}

void testSetHeight()
{
	cout << "********** setHeight() Test **********" << endl;

	TestPerson p1("Test Name", 0, "none", 42.5);
	cout << "Test Person with height: 42.5 instantiated!" << endl;

	p1.setHeight(88.7);
	cout << "setHeight(88.7) called. " << endl;
	cout << "getHeight() returned: " << p1.getHeight() << endl;

	if (p1.getHeight() == 88.7)
	{
		cout << "setHeight() test successful!" << endl;
	}
	else
	{
		cout << "setHeight() test failed!" << endl;
	}
	cout << endl;
}


// Operators
void testAssignment()
{
	cout << "********** Assignment Operator (=) Test **********" << endl;

	TestPerson p1("Test Name 1", 1, "Test Gender 1", 41.1);
	cout << "Test Person 1 with name: Test Name 1, age: 1, gender: Test Gender 1, height: 41.1 instantiated!" << endl;

	TestPerson p2("Test Name 2", 2, "Test Gender 2", 42.2);
	cout << "Test Person 2 with name: Test Name 2, age: 2, gender: Test Gender 2, height: 42.2 instantiated!" << endl;
	
	p1 = p2;
	cout << "p1 = p2 called." << endl;
	cout << "p1.getName() returned: " << p1.getName() << " p1.getAge() returned: " << p1.getAge() << " p1.getGender() returned: " << p1.getGender() << " p1.getHeight() returned: " << p1.getHeight() << endl;

	if (p1.getName() == "Test Name 2" && p1.getAge() == 2 && p1.getGender() == "Test Gender 2" && p1.getHeight() == 42.2)
	{
		cout << "Assignment Operator test successful!" << endl;
	}
	else
	{
		cout << "Assignment Operator test failed!" << endl;
	}
	cout << endl;
}