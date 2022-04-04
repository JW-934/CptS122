// We will place each class declaration
// in a separate .h file. Each .h file
// will be named the same as the class.

#pragma once

#include <iostream>
#include <fstream>

using std::cout; // we can now use cout without explicitly writing std::cout
using std::cin;
using std::endl;
using std::fstream;
using std::ostream;
using std::ifstream;

// Blueprint for a rational number
class Rational
{
public:
	// In here will be our well defined interfaces
	// to the object - member functions

	//Rational();
	//Rational(int newNumerator, int newDenominator);
	// constructor with default arguments - in general, replaces the need for other constructors, exclusing copy constructors
	Rational(const int newNumerator = 0, const int newDenominator = 1);

	// copy constructor - pass-by-value
	Rational(const Rational &copy);

	~Rational(); // destructor

	Rational & operator= (const Rational &rhs);

	Rational add(const Rational &rhs);

	// getters/accessors
	int getNumerator() const;
	int getDenominator() const;

	// setters/mutators
	void setNumerator(const int newNumerator);
	void setDenominator(const int newDenominator);

	//Rational add(Rational lhs, Rational rhs);

private:
	// attributes - data members
	// rational numbers may defined as:
	// numerator / denominator
	int mNumerator;
	int mDenominator;
};

// cout - ostream
// cin - istream
// cout << r1 << r2 << endl;
ostream& operator<< (ostream& lhs, const Rational& rhs);
Rational operator+ (const Rational& lhs, const Rational& rhs);
ifstream& operator>> (ifstream& lhs, Rational& rhs);

template <typename T> //<class T>
T operator- (const T& lhs, const T& rhs);

template <typename T> //<class T>
T operator- (const T& lhs, const T& rhs)
{
	T result;

	result.setDenominator(rhs.getDenominator() *
		lhs.getDenominator());
	result.setNumerator(rhs.getNumerator() * lhs.getDenominator() -
		lhs.getNumerator() * rhs.getDenominator());
	//return lhs - rhs;

	return result;
}