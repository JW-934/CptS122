/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 3
* Date: February 2, 2022
* Description: Stores contact information
*/

#include "Lab3.h"

// Description: Allocates space for a Node on the heap and initializes the Node with the information found in newData.
// Returns: The address of the start of the block of memory on the heap or NULL if no memory was allocated
Node* makeNode(Contact newData)
{
	Node* newNode = (Node *)malloc(sizeof(Node));

	if (newNode != NULL) // node memory allocated
	{
		newNode->data = newData;
		newNode->pNext = NULL;
		newNode->pPrev = NULL;
	}
	return newNode;
}

Contact searchForContact(Node* pList, char* name, Node** pPrevDelete)
{
	Node* pCur = pList, * pPrev = NULL;

	while (pCur != NULL && strcmp(pCur->data.name, name) != 0)
	{
		pPrev = pCur;
		pCur = pCur->pNext;
	}
	*pPrevDelete = pPrev;
	return pCur->data;
}

// Description: Uses makeNode () to allocate space for a new Node and inserts the new Node into the front of the list.
// Returns: TRUE if memory was allocated for a Node; FALSE otherwise
Boolean insertContactAtFront(Node** pList, Contact newData)
{

}

// Description: Uses makeNode () to allocate space for a new Node and inserts the new Node into the list in
//              alphabetic order ('a' - 'z') based on the name field
// Returns: TRUE if memory was  allocated for a Node; FALSE otherwise
Boolean insertContactInOrder(Node** pList, Contact newData)
{
	Node* newNode = makeNode(newData), *pCur = *pList, *pPrev = NULL;
	Boolean success = FALSE;

	if (newNode != NULL)
	{
		while (pCur != NULL && strcmp(pCur->data.name, newNode->data.name) < 0)
		{
			pPrev = pCur;
			pCur = pCur->pNext;
		}
		newNode->pNext = pCur;
		if (pPrev != NULL)
		{
			pPrev->pNext = newNode;
		}
		else
		{
			*pList = newNode;
		}
		success = TRUE;
	}
	return success;
}

// Description: Deletes a Contact in the list based on the name field; deletes the first occurrence of the name
// Returns: TRUE if the Contact was found; FALSE otherwise
Boolean deleteContact(Node** pList, Contact searchContact, Node* pPrevDelete)
{
	Node* pCur = *pList;
	Boolean success = FALSE;

	//while (pCur != NULL && strcmp(pCur->data.name, searchContact.name) != 0)
	//{
	//	// move the pointers to correct position in list
	//	pPrev = pCur;
	//	pCur = pCur->pNext;
	//}
	// guarantees we've positioned pointers correctly
	if (pCur != NULL)
	{
		success = TRUE;

		if (pPrevDelete == NULL)
		{
			// removing the first node
			// *pList = pCur
			*pList = pCur->pNext; // (* pList)->pNext;
		}
		else
		{
			// removing a node after the first one -- end/last node/middle
			// pPrev not null
			pPrevDelete->pNext = pCur->pNext;
		}
		free(pCur);
	}
	return success;
}

// Description: Edits a Contact in the list based on the name field; edits the first occurrence of the name
// Returns: TRUE if the Contact was found; FALSE otherwise
Boolean editContact(Node* pList, Contact searchContact)
{

}

// Description: Loads all Contact information from the given file, in alphabetic order, based on the name, into the list
// Returns: TRUE if all Contacts were loaded; FALSE otherwise
Boolean loadContacts(FILE* infile, Node** pList)
{
	char line[100] = "";
	Boolean success = FALSE;
	
	Contact newContact;

	while (fgets(line, 100, infile) != NULL)
	{
		////while (fgets(line, 100, infile))
		//{
		strcpy(newContact.name, strtok(line, ","));
		strcpy(newContact.phone, strtok(NULL, ","));
		strcpy(newContact.email, strtok(NULL, ","));
		strcpy(newContact.title, strtok(NULL, "."));
		strcat(newContact.title, ".");

		success = insertContactInOrder(pList, newContact);
	
		line[0] = '\0';
	}
		//success = insertContactInOrder(&pList, *newContact);
	//}
	return success;
}

// Description: Stores all Contact information from the list into the given file
// Returns: TRUE if all Contacts were stored; FALSE otherwise
Boolean storeContacts(FILE* infile, Node* pList) 
{

}

int getOption()
{
	int option = 0;
	printMenu();
	do
	{
		printf("Make your selection > ");
		scanf("%d", &option);
	} while (option < 1 || option > 7 || option == 0);
	return option;
}

// Description: Prints all contact information in the list
// Returns: Nothing
void printList(Node* pList)
{
	if (pList != NULL)
	{
		printf("--> %s, %s, %s, %s\n", pList->data.name, pList->data.phone, pList->data.email, pList->data.title);
		printList(pList->pNext);
	}
	else // base case
	{
		//printf(" -->\n");
		printf("\n");
	}
}

void printMenu()
{
	printf("********** Contact Information **********\n\n");
	printf("1. Add Contact\n");
	printf("2. Remove Contact\n");
	printf("3. Edit Contact\n");
	printf("4. Print Contact\n");
	printf("5. Store Contact\n");
	printf("6. Load Contact\n");
	printf("7. Exit\n\n");
}