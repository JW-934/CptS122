/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 5
* Date: February 16, 2022
* Description: Basic C++ Member Functions
*/

#include "Tests.h"
#include "Complex.h"
#include "Lab 5.h"

using std::cout;
using std::cin;

void testAdd()
{
    Complex c1(3.5, 2), c2(5.5, 7), c3;

    c3 = c1.add(c2);  // member add () function

    c3 = add(c1, c2); // non-member add () function

    c3 = c1 + c2;       // overloaded + operator
}

void testSubtract()
{
    Complex c1(3.5, 2), c2(5.5, 7), c3;

    c3 = c1 - c2;       // overloaded + operator
}

void testStreamExtraction()
{
    Complex c1(3.5, 2), c2(5.5, 7), c3;
    
    cout << "Enter a complex number in the form a + bi: ";
    c1.read();

    cout << "Enter a complex number in the form a + bi: ";
    c2.read();

    cout << "Enter two complex numbers in the form a + bi(each separated by whitespace) : ";
    cin >> c1 >> c2;
}

void testStreamInsertion()
{
    Complex c1(3.5, 2), c2(5.5, 7), c3;

    c1.print();
    c2.print();
    c3.print();

    cout << c1 << " " << c2 << " " << c3 << endl;
}