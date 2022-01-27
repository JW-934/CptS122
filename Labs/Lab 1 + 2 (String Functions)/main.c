/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 1 + 2
* Date: January 26, 2022
* Description: functions to reverse a string, break a string into tokens,
*			   and merge unsorted strings together into sorted order
*/

#include "lab1+2.h"

int main(void)
{
	int reverseIndex = 0;

	/*char str1[] = "abcdefg";
	myStrrev(str1, reverseIndex);*/

	char str2[] = ",,hello";
	printf("%s", myStrTok(str2, ","));

	return 0;
}