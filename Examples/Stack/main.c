/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Date: January 31, 2022, February 2, 2022, February 7, 2022
* Description: Stack Example
*/

#include "Stack.h"
#include "TestStack.h"
#include "reverseString.h"

int main(void)
{
	char str[10] = "cat";	// char* str = "cat"; would be immutable

	puts(str);
	puts(reverseString(str));

	return 0;
}