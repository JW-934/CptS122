/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Date: January 31, 2022, February 2, 2022, February 7, 2022, February 9, 2022
* Description: Stack Example
*/

#include "TestStack.h"

void testPushOnEmptyStack()
{
	// test points - actual values that are known and used in the test
	// case. we can then evaluate the actual result vs. the expected result

	Stack s = { NULL };
	Data d = { 'A' };
	int success = 0;

	// expected results: 
	// top pointer is not NULL
	// check and verify data in the top of stack is 'A'
	// success = 1;
	// next pointer = NULL (only one node bc list started empty)
	success = push(&s, &d);

	// evaluate actual results and compare to the expected results
	if (s.pTop != NULL)
	{
		printf("Set the top pointer to an address of node on the heap successfully\n");

		if (s.pTop->pItem->letter == 'A')
		{
			printf("Succeeded at adding data to the top node.\n");
		}
		else
		{
			printf("Failed to insert data in top node\n");
		}
		if (s.pTop->pNext == NULL)
		{
			printf("Succeeded at setting pNext to NULL.\n");
		}
		else
		{
			printf("Failed to set pNext to NULL\n");
		}
	}
	else
	{
		printf("Failed to set top pointer or failed to allocate space\n");
	}
	if (success == 1)
	{
		printf("Succeeded at returning the correct success state\n");
	}
	else
	{
		printf("Failed to return success - didn't actually allocate space on heap\n");
	}
}