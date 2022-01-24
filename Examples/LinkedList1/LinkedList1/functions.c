/*
Programmer: Jesse Watson
Date: January 21, 2022
Class: Cpt_S 122 Spring 2022
Description: Example of a linked list
*/

#include "linkedlist1.h"

Node* makeNode(char* newMovieTitle, int newYear)
{
	Node* pMem = (Node *) malloc(sizeof(Node)); // 58 bytes allocated // explicit cast to Node * not req

	if (pMem != NULL)
	{
		// allocated space for Node successfully, can initialize
		pMem->year = newYear;
		strcpy(pMem->movieTitle, newMovieTitle);
		pMem->pNext = NULL; // assume no next Node, this isn't an insert function
	}
	return pMem;
}

int insertFront(Node** pList, char* newMovieTitle, int newYear)
{
	Node* pMem = makeNode(newMovieTitle, newYear);
	int success = 0;

	// think state of linked list
	// 2 states: empty, not empty

	if (pMem != NULL) // successfully allocated space on heap for Node
	{
		if (*pList == NULL) // if null, list empty
		{
			*pList = pMem;
		}
		else // not empty
		{

		}
	}
}