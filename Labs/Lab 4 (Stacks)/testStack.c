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
	printf("********** push() test **********\n");

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
		printf("push() Success: returned the correct success state.\n");
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
	puts("Test Complete.\n");
}

void testIsEmpty()
{
	printf("********** isEmpty() test **********\n");

	Stack empty = { NULL };
	Stack notEmpty = { NULL };
	int isEmptyEmpty = 0, isNotEmptyEmpty = 0;

	push(&notEmpty, 10);

	if (notEmpty.pTop->number == 10)
	{
		printf("Pushed test node to non-empty test stack.\n");

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
	}
	else
	{
		printf("Failed to push test node to non-empty test stack.\n");
	}
	//putchar('\n');
	puts("Test Complete.\n");
}

void testPeek()
{
	printf("********** peek() test **********\n");

	Stack s = { NULL };
	double testValue = 0;
	push(&s, 10);

	if (s.pTop->number == 10)
	{
		printf("Pushed test node to test stack.\n");
		testValue = peek(&s);

		if (testValue == 10)
		{
			printf("peek() Success: returned test value from stack.\n");
		}
		else
		{
			printf("peek() Failure: failed to read test value from stack.\n");
		}
	}
	else
	{
		printf("Failed to push test node to test stack.\n");
	}
	//putchar('\n');
	puts("Test Complete.\n");
}

void testPop()
{
	printf("********** pop() test **********\n");
	
	Stack s = { NULL };
	stackNode* temp = s.pTop;
	push(&s, 10);

	if (s.pTop->number == 10)
	{
		printf("Test node pushed to test stack.\n");
		pop(&s);
		if (temp == NULL)
		{
			printf("pop() Success: test node freed.\n");
		}
		else
		{
			printf("pop() Failure: failed to free test node.\n");
		}
	}
	else
	{
		printf("Failed to push test node to test stack.\n");
	}
	puts("Test Complete.\n");
}