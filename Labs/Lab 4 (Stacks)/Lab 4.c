/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 4
* Date: February 9, 2022
* Description: Stack operations and Towers of Hanoi
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
	Stack tower1 = { NULL }, tower2 = { NULL }, tower3 = { NULL }, *srcStk = { NULL }, *destStk = { NULL };
	int gameFinished = 0;

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

	do
	{
		promptForTowers(&destStk, &srcStk, &tower1, &tower2, &tower3);

		moveTopNode(&destStk, &srcStk);

		//moveTopNode(&tower2, &tower1);

		system("cls");

		printf("Tower 1: ");
		printStack(&tower1);

		printf("Tower 2: ");
		printStack(&tower2);

		printf("Tower 3: ");
		printStack(&tower3);
	} while (gameFinished == 0);
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

void promptForTowers(Stack* destStk, Stack* srcStk, Stack* stk1, Stack* stk2, Stack* stk3)
{
	int source = 0, dest = 0;

	do
	{
		printf("Which tower's top ring do you want to move (1, 2, 3)?\n> ");
		scanf("%d", &source);
	} while (source < 1 || source > 3);
	do
	{
		printf("\nWhich tower do you want to move said ring to (1, 2, 3)?\n> ");
		scanf("%d", &dest);
	} while (dest < 1 || source > 3);

	if (source == 1)
	{
		srcStk = stk1;
	}
	else if (source == 2)
	{
		srcStk = stk2;
	}
	else if (source == 3)
	{
		srcStk = stk3;
	}

	if (dest == 1)
	{
		destStk = stk1;
	}
	else if (dest == 2)
	{
		destStk = stk2;
	}
	else if (dest == 3)
	{
		destStk = stk3;
	}
}