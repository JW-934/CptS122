/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 8
* Date: March 9, 2022
* Description: Implementation of a binary search tree
*/

#include "Dog.h"

Dog::Dog(void) :itsAge(1)
{
    cout << "Dog constructor..." << endl;
}

Dog::~Dog(void)
{
    cout << "Dog destructor..." << endl;
}

void Dog::Move() const
{
    cout << "Dog moves a step!" << endl;
}

void Dog::Speak() const
{
    cout << "Bark!" << endl;
}