/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 3
* Date: February 2, 2022
* Description: Stores contact information
*/

#include "Lab3.h"

int main(void)
{
	int option = 0;
	Node* pHead = NULL, * pPrevDelete = NULL;
	FILE* infile = NULL;
	Boolean loadSuccess = FALSE;
	char nameRemove[25] = "";
	Contact delete;

	do
	{
		option = getOption();

		switch (option)
		{
		case 1: // add
			break;
		case 2: // remove
			system("cls");
			printList(pHead);

			printf("Enter the name of the contact to delete > ");
			scanf(" %[^\n]s", nameRemove);

			delete = searchForContact(pHead, nameRemove, &pPrevDelete);

			deleteContact(&pHead, delete, pPrevDelete);

			printList(pHead);
			//puts(nameRemove);
			break;
		case 3: // edit
			break;
		case 4: // print
			printList(pHead);
			break;
		case 5: // store
			break;
		case 6: // load
			system("cls");
			
			infile = fopen(INPUTFILE, "r");

			if (infile != NULL)
			{
				loadSuccess = loadContacts(infile, &pHead);
				if (loadSuccess == TRUE)
				{
					printf("\nContacts loaded!\n\n");
				}
				fclose(infile);
			}
			else
			{
				printf("Could not access contact file!\n");
			}
			break;
		case 7: // exit
			break;
		}
	} while (option != 7);
	return 0;
}