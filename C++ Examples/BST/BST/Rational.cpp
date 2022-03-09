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

Rational& Rational::operator= (const Rational& rhs)
{

	if (this != &rhs) // check for self-assignment
	{
		setNumerator(rhs.mNumerator);
		setDenominator(rhs.mDenominator);
	}

	return *this; // stores the address of the instance of the object which is invoking the operation
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
	Rational result;

	result.setDenominator(rhs.getDenominator() *
		getDenominator());
	result.setNumerator(rhs.getNumerator() * getDenominator() +
		getNumerator()*rhs.getDenominator());

	return result;
}

Rational::~Rational()
{
	cout << "Inside destructor for Rational" << std::endl;
}

ostream& operator<<(ostream& lhs, const Rational& rhs)
{
	lhs << rhs.getNumerator() << " / " << rhs.getDenominator();

	return lhs;
}

Rational operator+ (const Rational& lhs, const Rational& rhs)
{
	Rational result;

	result.setDenominator(rhs.getDenominator() *
		lhs.getDenominator());
	result.setNumerator(rhs.getNumerator() * lhs.getDenominator() +
		lhs.getNumerator() * rhs.getDenominator());

	return result;
}

ifstream& operator>> (ifstream& lhs, Rational& rhs)
{
	int num = 0, den = 0;
	char slash = '\0';

	lhs >> num;
	rhs.setNumerator(num);
	lhs >> slash;
	lhs >> den;
	rhs.setDenominator(den);

	return lhs;
}

bool operator< (const Rational& lhs, const Rational& rhs)
{
	return lhs.getNumerator() * rhs.getDenominator() < rhs.getNumerator() * lhs.getDenominator();
}