/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Date: January 31, 2022, February 2, 2022, February 7, 2022, February 9, 2022
* Description: Stack Example
*/

#include "reverseString.h"

char* reverseString(char* const str)
{
	Stack stck = { NULL };
	Data d = { '\0' };
	int index = 0;

	while (str[index] != '\0')
	{
		// push data to stack
		d.letter = str[index];
		push(&stck, &d); // address of data to save space, could be problem if dangling pointer but makeNode() protects against that
		++index;
	}
	// have a populated stack
	index = 0;
	while (!isEmpty(&stck)) // go until stack is empty
	{
		d = peek(&stck); // struct assignment (shallow assignment: copies pointer not data)
		str[index] = d.letter;
		pop(&stck);
		++index;
	}
	return str;
}