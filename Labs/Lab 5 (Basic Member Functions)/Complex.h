/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 5
* Date: February 16, 2022
* Description: Basic C++ Member Functions
*/

#pragma once

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Complex
{
public:
	// constructors
	Complex(double newReal = 0.0, double newImaginary = 0.0);

	// destructor 
	~Complex();

	// getters
	double getReal() const;
	double getImaginary() const;

	// setters
	void setReal(const double newReal);
	void setImaginary(const double newImaginary);

	// operations
	Complex add(const Complex &rhs);
	void read();
	void print();

private:
	// data members
	double realPart;
	double imaginaryPart;
};

Complex add(const Complex& lhs, const Complex& rhs);

// Operators
Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
std::istream& operator>> (std::istream& lhs, Complex& rhs);

void promptForComplex();