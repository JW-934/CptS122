/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 8
* Date: March 9, 2022
* Description: Implementation of a binary search tree
*/

#pragma once

#include <iostream>

using std::cout;
using std::endl;

class Base
{
public:
    virtual void testFunction();
};

class Derived : public Base
{
public:
    void testFunction();
};