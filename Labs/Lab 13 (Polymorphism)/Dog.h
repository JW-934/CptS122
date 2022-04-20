/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 8
* Date: March 9, 2022
* Description: Implementation of a binary search tree
*/

#pragma once

#include "Mammal.h"

class Dog : public Mammal
{
public:
    Dog(void);
    ~Dog(void);

    void Move() const;
    void Speak() const;
protected:
    int itsAge;
};