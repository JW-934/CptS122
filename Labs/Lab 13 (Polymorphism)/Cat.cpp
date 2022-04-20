/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 8
* Date: March 9, 2022
* Description: Implementation of a binary search tree
*/

#include "Cat.h"

Cat::Cat(void) :itsAge(1)
{
    cout << "Cat constructor..." << endl;
}

Cat::~Cat(void)
{
    cout << "Cat destructor..." << endl;
}

void Cat::Move() const
{
    cout << "Cat moves a step!" << endl;
}

void Cat::Speak() const
{
    cout << "Meow!" << endl;
}