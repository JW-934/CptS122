/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA7
* Date: March 27, 2022, April 4, 2022
* Description: This application manages attendance for a course.
*/

#pragma once

#include <string>
#include "Stack.h"

using std::string;
using std::ostream;

class Data
{
public:
	Data(const int newRecord = 0, const int newID = 0, const string newName = " ", const string newEmail = " ", const int newUnits = 0, const string newMajor = " ", const string newLevel = " ");

	~Data();

	int getRecordNum();
	int getID();
	string getName();
	string getEmail();
	int getUnits();
	string getMajor();
	string getLevel();

private:
	int mRecordNum;
	int mID;
	string mName;
	string mEmail;
	int mUnits;
	string mMajor;
	string mLevel;

	int mNumAbsences;
	Stack<string>* mAbsenceDates;
};

ostream& operator<< (ostream& lhs, const Data& rhs);