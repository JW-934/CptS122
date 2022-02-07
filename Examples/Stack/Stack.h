/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Date: January 31, 2022, February 2, 2022, February 7, 2022
* Description: Stack Example
*/

#ifndef STACK_H

#define STACK_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data
{
	char letter;
}Data;

typedef struct node
{
	Data* pItem; // only an address that can refer to Data
	struct node* pNext;
}Node;

typedef struct stack
{
	Node* pTop; // essentially a pHead
}Stack;

Node* makeNode(const Data * const pNewItem);

int push(Stack *pStack, const Data* const pNewItem); // not ** because one of the stars is encapsulated inside the Stack struct
// defensive vs. cooperative programming, defensive checks if empty etc, cooperative sets a precondition
// precondition: stack is not empty
void pop(Stack* pStack);
Data peek(Stack* pStack); // No star required bc not modifying stack, just has one to save space to not copy stack

int isEmpty(Stack* pStack);
#endif
