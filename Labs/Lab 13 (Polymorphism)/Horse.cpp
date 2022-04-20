/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 8
* Date: March 9, 2022
* Description: Implementation of a binary search tree
*/

#include "Horse.h"

Horse::Horse(void) :itsAge(1)
{
    cout << "Horse constructor..." << endl;
}

Horse::~Horse(void)
{
    cout << "Horse destructor..." << endl;
}

void Horse::Move() const
{
    cout << "Horse moves a step!" << endl;
}

void Horse::Speak() const
{
    cout << "Neigh!" << endl;
}