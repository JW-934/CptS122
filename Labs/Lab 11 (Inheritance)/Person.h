/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 8
* Date: March 9, 2022
* Description: Implementation of a binary search tree
*/

#pragma once

#include <string>
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ostream;
using std::ifstream;
using std::string;

class Person
{
public:
	Person(const string newName = "", const int newAge = 0, const string newGender = "", const double newHeight = 0.0);

	Person(const Person& copy);

	~Person();

	// Getters
	string getName() const;
	int getAge() const;
	string getGender() const;
	double getHeight() const;

	// Setters
	void setName(const string newName);
	void setAge(const int newAge);
	void setGender(const string newGender);
	void setHeight(const double newHeight);

	// Operations 
	Person& operator= (const Person& rhs);

private:
	string mName;
	int mAge;
	string mGender;
	double mHeight;
};

// Non Members
ostream& operator<< (ostream& lhs, const Person& rhs);
ifstream& operator>> (ifstream& lhs, Person& rhs);