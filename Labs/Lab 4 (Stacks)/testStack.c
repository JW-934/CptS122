/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 4
* Date: February 9, 2022
* Description:
*/

#include "Lab 4.h"

void testPush()
{
	Stack s = {NULL};
	int success = 0;

	success = push(&s, 10);

	if (s.pTop != NULL)
	{
		printf("push() Success: set top pointer to the address of a node.\n");

		if (s.pTop->number == 10)
		{
			printf("push() Success: set number field in node.\n");
		}
		else
		{
			printf("push() Failure: failed to set number field in node.\n");
		}
		if (s.pTop->pNext == NULL)
		{
			printf("push() Success: set pNext to NULL.\n");
		}
		else
		{
			printf("push() Failure: failed to set pNext to NULL.\n");
		}
	}
	else
	{
		printf("push() Failure: failed to set top pointer or failed to allocate space.\n");
	}
	if (success == 1)
	{
		printf("push() success: returned the correct success state.\n");
	}
	else
	{
		printf("push() Failure: failed to return success - didn't  allocate space on heap.\n");
	}
	/*if (s.pTop->number == 10)
	{
		printf("Successfully pushed to stack.\n");
	}
	else
	{
		printf("Failed to push to stack.\n");
	}*/
	putchar('\n');
}

void testIsEmpty()
{
	Stack empty = { NULL };
	Stack notEmpty = { NULL };
	int isEmptyEmpty = 0, isNotEmptyEmpty = 0;

	push(&notEmpty, 10);

	isNotEmptyEmpty = isEmpty(&notEmpty);

	if (isNotEmptyEmpty == 0)
	{
		printf("isEmpty() Success: determined that populated stack is not empty.\n");
	}
	else
	{
		printf("isEmpty() Failure: did not determine that populated stack is not empty.\n");
	}

	isEmptyEmpty = isEmpty(&empty);

	if (isEmptyEmpty == 1)
	{
		printf("isEmpty() Success: determined that empty stack is empty.\n");
	}
	else
	{
		printf("isEmpty() Failure: did not determine that empty stack is empty.\n");
	}
	putchar('\n');
}

void testPop()
{
	Stack s = { NULL };
	double testValue = 0;
	push(&s, 10);

	testValue = peek(&s);

	if (testValue == 10)
	{
		printf("pop() Success: read test value from stack.\n");
	}
	else
	{
		printf("pop() Failure: failed to read test value from stack.\n");
	}
	putchar('\n');
}