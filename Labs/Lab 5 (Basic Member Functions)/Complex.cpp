/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 5
* Date: February 16, 2022
* Description: Basic C++ Member Functions
*/

#include "Complex.h"

// constructors
Complex::Complex(double newReal, double newImaginary)
{
	realPart = newReal;
	imaginaryPart = newImaginary;
}

// destructor
Complex::~Complex()
{

}

// getters
double Complex::getReal() const
{
	return realPart;
}

double Complex::getImaginary() const
{
	return imaginaryPart;
}

// setters
void Complex::setReal(const double newReal)
{
	realPart = newReal;
}

void Complex::setImaginary(const double newImaginary)
{
	imaginaryPart = newImaginary;
}

// operations
Complex Complex::add(const Complex& rhs)
{
	Complex result;

	result.realPart = rhs.realPart + result.realPart;

	result.imaginaryPart = rhs.realPart + result.imaginaryPart;

	return result;
}

void Complex::read()
{
	char plus, i;
	cin >> realPart >> plus >> imaginaryPart >> i;
}

void Complex::print()
{
	cout << realPart << " + " << imaginaryPart << "i" << endl;
}

Complex add(const Complex& lhs, const Complex& rhs)
{
	Complex result;

	result.setReal(rhs.getReal() + lhs.getReal());
	result.setImaginary(rhs.getImaginary() + lhs.getImaginary());

	return result;
}

// Operators
Complex operator+(const Complex& lhs, const Complex& rhs)
{
	Complex result;

	result.setReal(rhs.getReal() + lhs.getReal());
	result.setImaginary(rhs.getImaginary() + rhs.getImaginary());

	return result;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
	Complex result;

	result.setReal(lhs.getReal() - rhs.getReal());
	result.setImaginary(lhs.getImaginary() - rhs.getImaginary());

	return result;
}

istream& operator>> (std::istream& lhs, Complex& rhs)
{
	char plus, i;
	double newReal, newImaginary;

	lhs >> newReal >> plus >> newImaginary >> i;
	rhs.setReal(newReal);
	rhs.setImaginary(newImaginary);

	return lhs;
}

ostream& operator<< (ostream& lhs, const Complex& rhs)
{
	lhs << rhs.getReal() << " + " << rhs.getImaginary() << "i";

	return lhs;
}

void promptForComplex()
{
	cout << "Enter a complex number (a + bi) > ";
}