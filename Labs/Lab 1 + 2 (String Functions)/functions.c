/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 1 + 2
* Date: January 26, 2022
* Description: functions to reverse a string, break a string into tokens,
*			   and merge unsorted strings together into sorted order
*/

#include "lab1+2.h"

void myStrrev(char* str, int index)
{
	if (str[index] == '\0')
	{
		return;
	}
	else
	{
		myStrrev(str, index + 1);
		printf("%c", str[index]);
	}
}