/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 8
* Date: March 9, 2022
* Description: Implementation of a binary search tree
*/

#include "Mammal.h"

Mammal::Mammal(void) :itsAge(1)
{
    cout << "Mammal constructor..." << endl;
}

Mammal::~Mammal(void)
{
    cout << "Mammal destructor..." << endl;
}

void Mammal::Move() const
{
    cout << "Mammal moves a step!" << endl;
}

void Mammal::Speak() const
{
    cout << "What does a mammal speak? Mammilian!" << endl;
}
