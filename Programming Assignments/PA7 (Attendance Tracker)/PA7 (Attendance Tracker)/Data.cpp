/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA7
* Date: March 27, 2022, April 4, 2022, April 7, 2022
* Description: This application manages attendance for a course.
*/

#include "Data.h"

Data::Data(const int newRecord, const int newID, const string newName, const string newEmail, const int newUnits, const string newMajor, const string newLevel)
{
	mRecordNum = newRecord;
	mID = newID;
	mName = newName;
	mEmail = newEmail;
	mUnits = newUnits;
	mMajor = newMajor;
	mLevel = newLevel;

	mNumAbsences = 0;
	mAbsenceDates = new Stack<string>;
}

Data::~Data()
{

}

int Data::getRecordNum() const
{
	return mRecordNum;
}

int Data::getID() const
{
	return mID;
}

string Data::getName() const
{
	return mName;
}

string Data::getEmail() const
{
	return mEmail;
}

int Data::getUnits() const
{
	return mUnits;
}

string Data::getMajor() const
{
	return mMajor;
}

string Data::getLevel() const
{
	return mLevel;
}

ostream& operator<< (ostream& lhs, const Data& rhs)
{
	lhs << rhs.getRecordNum() << " " << rhs.getID() << " " << rhs.getName() << " " << rhs.getEmail() << " " << rhs.getUnits() << " "
		<< rhs.getMajor() << " " << rhs.getLevel() << endl;

	return lhs;
}