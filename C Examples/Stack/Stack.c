/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Date: January 31, 2022, February 2, 2022, February 7, 2022, February 9, 2022
* Description: Stack Example
*/

#include "Stack.h"

Node* makeNode(const Data* const pNewItem)
{
	Node* pMem = (Node*)malloc(sizeof(Node)); // 4 bytes for next ptr, 4 bytes for ptr to data

	// still need to allocate space for the actual data

	if (pMem != NULL)
	{
		// allocated space on heap for a Node
		// need to allocate space for the Data now
		pMem->pItem = (Data*)malloc(sizeof(Data));

		if (pMem->pItem != NULL)
		{
			// allocated space for Data, need to initialize
			pMem->pNext = NULL;
			pMem->pItem->letter = pNewItem->letter; // pMem->pItem = pNewItem won't work
		}
		else
		{
			// failed to allocate Data, but allocated Node; so free the Node because it is incomplete
			free(pMem);
			pMem = NULL; // set to NULL here so we don't return a dangling pointer
		}
	}
	return pMem;
}

int push(Stack* pStack, const Data* const pNewItem) // essentially insert at front
{
	Node* pMem = makeNode(pNewItem);
	int success = 0;

	if (pMem != NULL)
	{
		// allocated space for Node and for pItem = Data
		success = 1;

		pMem->pNext = pStack->pTop;
		pStack->pTop = pMem;
	}
	return success;
}

// precondition: stack is not empty
void pop(Stack* pStack)
{
	Node* pTemp = pStack->pTop;

	pStack->pTop = pStack->pTop->pNext; // or pTemp->pNext;

	free(pTemp);
}

Data peek(Stack* pStack)
{
	return *(pStack->pTop->pItem);
}

int isEmpty(Stack* pStack)
{
	return pStack->pTop == NULL; // return !pStack->pTop
}