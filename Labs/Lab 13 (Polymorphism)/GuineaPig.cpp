/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 8
* Date: March 9, 2022
* Description: Implementation of a binary search tree
*/

#include "GuineaPig.h"

GuineaPig::GuineaPig(void) :itsAge(1)
{
    cout << "GuineaPig constructor..." << endl;
}

GuineaPig::~GuineaPig(void)
{
    cout << "GuineaPig destructor..." << endl;
}

void GuineaPig::Move() const
{
    cout << "GuineaPig moves a step!" << endl;
}

void GuineaPig::Speak() const
{
    cout << "Weep weep!" << endl;
}