/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 4
* Date: February 9, 2022
* Description:
*/

#ifndef LAB4_H

#define LAB4_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stackNode
{
	double number;
	struct stackNode* pNext;
}stackNode;

typedef struct stack
{
	stackNode* pTop;
}Stack;

int push(Stack* pStack, double newNumber);

int isEmpty(Stack* pStack);

double peek(Stack* pStack);

stackNode* makeNode(double number);

void pop(Stack* pStack);
#endif
