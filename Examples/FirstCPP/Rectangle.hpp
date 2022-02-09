/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Date: February 7, 2022, February 9, 2022
* Description: Introduction to C++
*/

#pragma once

#include <iostream>
#include <string>

// using namespace std; terrible idea, opens up name collision possibility

using std::cout;

// overloaded functions possible in C++
// params must be different
int add(int n1, int n2);
double add(double n1, double n2);
std::string add(std::string n1, std::string n2);

class Rectangle // make custom classes uppercase
{

private:
	double mLength; // the m is for member
	double mWidth;
};