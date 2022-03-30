/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 8
* Date: March 9, 2022
* Description: Implementation of a binary search tree
*/

#include "Person.h"

Person::Person(const string newName, const int newAge, const string newGender, const double newHeight)
{
	mName = newName;
	mAge = newAge;
	mGender = newGender;
	mHeight = newHeight;
}

Person::Person(const Person& copy) 
{
	setName(copy.mName);
	setAge(copy.mAge);
	setGender(copy.mGender);
	setHeight(copy.mHeight);
}

Person::~Person() 
{

}

// Getters
string Person::getName() const
{
	return mName;
}

int Person::getAge() const
{
	return mAge;
}

string Person::getGender() const
{
	return mGender;
}

double Person::getHeight() const
{
	return mHeight;
}

// Setters
void Person::setName(const string newName)
{
	mName = newName;
}

void Person::setAge(const int newAge)
{
	mAge = newAge;
}

void Person::setGender(const string newGender)
{
	mGender = newGender;
}

void Person::setHeight(const double newHeight)
{
	mHeight = newHeight;
}

// Operations 
Person& Person::operator= (const Person& rhs)
{
	if (this != &rhs)
	{
		setName(rhs.mName);
		setAge(rhs.mAge);
		setGender(rhs.mGender);
		setHeight(rhs.mHeight);
	}
	return *this;
}

// Non Members
ostream& operator<< (ostream& lhs, const Person& rhs)
{
	cout << "Name: " << rhs.getName() << " Age: " << rhs.getAge() << " Gender: " << rhs.getGender() << " Height: " << rhs.getHeight();

	return lhs;
}

ifstream& operator>> (ifstream& lhs, Person& rhs)
{
	int age, height;
	string name, gender;

	lhs >> name;
	rhs.setName(name);
	lhs >> age;
	rhs.setAge(age);
	lhs >> gender;
	rhs.setGender(gender);
	lhs >> height;
	rhs.setHeight(height);

	return lhs;
}