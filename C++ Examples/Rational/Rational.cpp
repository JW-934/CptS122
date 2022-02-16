// We will place the definitions for only
// Rational's operations in this file

#include "Rational.h"

//Rational::Rational()
//{
//	mNumerator = 0;
//	mDenominator = 1;
//}
//
//Rational::Rational(int newNumerator, int newDenominator)
//{
//	mNumerator = newNumerator;
//	mDenominator = newDenominator;
//}

Rational& Rational::operator= (const Rational& rhs) // member function so can access private data members
{
	if (this != &rhs) // checking for self assignment; in this context & is the address of operator not a reference
	{
		setNumerator(rhs.mNumerator); // setters validate data
		setDenominator(rhs.mDenominator);
	}
	return *this; // stores the address of the instance of the object which is invoking the operation; need star to return as reference
				  // no dangling reference because function can only be called if the object exists
}

Rational::Rational(const int newNumerator, const int newDenominator)
{
	mNumerator = newNumerator;

	// validate the denominator
	if (newDenominator != 0)
	{
		mDenominator = newDenominator;
	}
	else
	{
		mDenominator = 1;
	}
}

int Rational::getNumerator() const
{
	return mNumerator;
}

int Rational::getDenominator() const
{
	return mDenominator;
}


void Rational::setNumerator(const int newNumerator)
{
	mNumerator = newNumerator;
}

void Rational::setDenominator(const int newDenominator)
{
	// validate the denominator
	if (newDenominator != 0)
	{
		mDenominator = newDenominator;
	}
}

// implicitly called when passing-by-value
Rational::Rational(const Rational &copy)
{
	//mNumerator = copy.mNumerator; // could also work
	setNumerator(copy.getNumerator());
	setDenominator(copy.getDenominator());

	// let's rewrite using the copy assignment operator!
}

Rational Rational::add(const Rational &rhs)
{
	Rational result; // calls default constructor

	result.setDenominator(rhs.getDenominator() *
		getDenominator()); // this getDenom has no rhs. but other operand does so both use it
	result.setNumerator(rhs.getNumerator() * getDenominator() +
		getNumerator()*rhs.getDenominator());

	return result; // calls constructor to make copy of rational
}

Rational::~Rational()
{
	cout << "Inside destructor for Rational" << std::endl;
}

ostream& operator<< (ostream& lhs, const Rational& rhs) // only need to modify stream; passing in by reference so we know it exists (no risk of dangling reference when returning)
{
	lhs << rhs.getNumerator() << " / " << rhs.getDenominator();

	return lhs;
}


Rational operator+ (const Rational& lhs, const Rational& rhs) // don't actually need to modify Rationals
{
	Rational result; // calls default constructor

	result.setDenominator(rhs.getDenominator() *
		lhs.getDenominator()); // this getDenom has no rhs. but other operand does so both use it
	result.setNumerator(rhs.getNumerator() * lhs.getDenominator() +
		lhs.getNumerator() * rhs.getDenominator());

	return result; // calls constructor to make copy of rational
}