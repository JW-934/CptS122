/*
Programmer: Jesse Watson
Date: January 21, 2022
Class: Cpt_S 122 Spring 2022, January 24, 2022, January 26, 2022
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
		pMem->pPrev = NULL; // for doubly linked list
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
		//if (*pList == NULL) // if null, list empty
		//{
		//	*pList = pMem;
		//}
		//else // not empty
		//{
		//	pMem->pNext = *pList;
		//	*pList = pMem;
		//}

		// --> empty list
		// --> <--N1--><--N2-->

		//if (*pList == NULL)
		//{
		//	// empty list
		//	//*pList = pMem;
		//}
		//else

		if(*pList != NULL)
		{
			// not empty
			(*pList)->pPrev = pMem; // doubly link
			pMem->pNext = *pList;
			//*pList = pMem;
		}
		*pList = pMem;
		success = 1;
	}
	return success;
}

int insertInOrder(Node** pList, char* newMovieTitle, int newYear)
{
	Node* pMem = makeNode(newMovieTitle, newYear), * pCur = *pList, *pPrev = NULL;
	int success = 0;

	if (pMem != NULL) // successfully allocated a Node
	{
		while (pCur != NULL && strcmp(pCur->movieTitle, pMem->movieTitle) < 0) // empty/end of list; order matters here so strcmp doesn't get passed NULL
		{
			// intent is to position the pointers to insertion point
			pPrev = pCur;
			pCur = pCur->pNext;
		}
		// should insert Node
		pMem->pNext = pCur;

		if (pPrev != NULL)
		{
			// inserting somewhere after first node, middle, or at end
			pPrev->pNext = pMem;
		}
		else
		{
			// inserting at front
			*pList = pMem;
		}
		success = 1;
	}
	return success;
}

int deleteItem(Node** pList, char* movieTitleSrch) //** pList is to change pList, not the list's contents (that's *pList)
{
	Node* pCur = *pList, * pPrev = NULL;
	int success = 0;

	while (pCur != NULL && strcmp(pCur->movieTitle, movieTitleSrch) != 0)
	{
		// move the pointers to correct position in list
		pPrev = pCur;
		pCur = pCur->pNext;
	}
	// guarantees we've positioned pointers correctly
	if (pCur != NULL)
	{
		// we found movie string in a Node
		success = 1;
		
		if (pPrev == NULL)
		{
			// removing the first node
			// *pList = pCur
			*pList = pCur->pNext; // (* pList)->pNext;
		}
		else
		{
			// removing a node after the first one -- end/last node/middle
			// pPrev not null
			pPrev->pNext = pCur->pNext;
		}
		free(pCur);
	}
	return success;
}

void printListRec(Node* pHead)
{
	if (pHead != NULL) // there is a movie to print, recursive step
	{
		printf("--> %s, %d", pHead->movieTitle, pHead->year); // arrow before to keep aesthetically clean
		printListRec(pHead->pNext); // pNext is address of next node
	}
	else // base case
	{
		printf(" -->\n");
	}
}