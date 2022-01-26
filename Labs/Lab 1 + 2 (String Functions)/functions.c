/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 1 + 2
* Date: January 26, 2022
* Description: functions to reverse a string, break a string into tokens,
*			   and merge unsorted strings together into sorted order
*/

#include "lab1+2.h"

char* myStrTok(char* str, char* delimiter)
{
	static char* pToken;
	pToken = str;
	int delimFound = 0, i = 0, k = 0, j = 0, charFound = 0;
	
	if (pToken != NULL) // first call
	{
		for (; i < strlen(pToken) && delimFound == 0; ++i) // looking for first non-delimiter
		{
			if (pToken[i] != delimiter)	// i will mark the location of the first non-delimiter
			{
				charFound = 1;
			}
		}
		if (charFound == 0) // no delimiters in string or no non-delimiter characters
		{
			return NULL;
		}
		k = i + 1;
		for (; k < strlen(pToken) && delimFound == 0; ++k) // looks for next delimiter
		{
			if (pToken[k] == delimiter) // k will mark the location of the next delimiter
			{
				delimFound = 1;
			}
		}
		if (delimFound = 0) // if no delimiter found after token
		{
			pToken[strlen(pToken) + 1] = '\0';
			
		}
		pToken[k] = '\0';
	}
	return pToken;
}
	

		









	//int nonDelim = 0, i = 0, strIndex = 0, k;
	//for (; i < strlen(pToken) && nonDelim == 0; ++i)
	//{
	//	if (pToken[i] != *delimiter)
	//	{
	//		nonDelim = 1;
	//		token[strIndex] = pToken[i];
	//	}
	//}
	//nonDelim = 0;
	//k = i;
	//for (int j = i; j < strlen(pToken) && nonDelim == 0; ++j)
	//{
	//	if (pToken[j] == *delimiter)
	//	{
	//		for (; k < j; ++k)
	//		{
	//			token[k] = pToken[i];
	//			++i;
	//		}
	//	}
	//}
	//token[k + 1] = '\0';
	//return token;


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