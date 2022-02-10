/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 4
* Date: February 9, 2022
* Description:
*/

#include "Lab 4.h"

int push(Stack* pStack, double newNumber)
{
	stackNode* pMem = makeNode(newNumber);
	int success = 0;

	if (pMem != NULL)
	{
		success = 1;

		pMem->pNext = pStack->pTop;
		pStack->pTop = pMem;
	}
	return success;
}

int isEmpty(Stack* pStack)
{
	return pStack->pTop == NULL;
}

double peek(Stack* pStack)
{
	return pStack->pTop->number;
}

stackNode* makeNode(double number)
{
	stackNode* pMem = (stackNode*)malloc(sizeof(stackNode));
	
	if (pMem != NULL)
	{
		pMem->number = number;
		pMem->pNext = NULL;
	}
	return pMem;
}

void pop(Stack* pStack)
{
	stackNode* pTemp = pStack->pTop;

	pStack->pTop = pStack->pTop->pNext;

	free(pTemp);
}

void hanoi()
{
	Stack tower1 = { NULL }, tower2 = { NULL }, tower3 = { NULL };

	// Populate first tower
	for (int i = 5; i > 0; --i)
	{
		push(&tower1, i);
		push(&tower2, 0);
		push(&tower3, 0);
	}
	
	printf("Tower 1: ");
	printStack(&tower1);

	printf("Tower 2: ");
	printStack(&tower2);

	printf("Tower 3: ");
	printStack(&tower3);

	system("cls");

	moveTopNode(&tower3, &tower1);

	printf("Tower 1: ");
	printStack(&tower1);

	printf("Tower 2: ");
	printStack(&tower2);

	printf("Tower 3: ");
	printStack(&tower3);
}

void printStack(Stack* stack)
{
	stackNode* pCur = stack->pTop;

	if (pCur != NULL) // list is not empty
	{
		while (pCur != NULL)
		{
			printf("<---%.0lf", pCur->number);
			pCur = pCur->pNext;
		}
	}
	puts("\n\n");
}

void moveTopNode(Stack* destStk, Stack* srcStk)
{
	double nodeValue = peek(srcStk);

	//pop(destStk);
	push(destStk, nodeValue);
	pop(srcStk);
	push(srcStk, 0);
}