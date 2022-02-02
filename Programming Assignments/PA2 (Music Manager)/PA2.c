/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA2
* Date: January 27, 2022, January 28, 2022, February 1, 2022
* Description: a basic digital music manager
*/

#include "PA2.h"

// Create a new Node and put it at the front of the list
int insertFront(Node** pList, char* artist, char* albumTitle, char* songTitle, char* genre, int minutes, int seconds, int timesPlayed, int rating)
{
	Node* newNode = makeNode(artist, albumTitle, songTitle, genre, minutes, seconds, timesPlayed, rating);
	int success = 0;

	if (newNode != NULL) // successfully allocated space on heap for Node
	{
		if (*pList != NULL)
		{
			// not empty
			(*pList)->pPrev = newNode; // doubly link
			newNode->pNext = *pList;
			//*pList = pMem;
		}
		*pList = newNode;
		success = 1;
	}
	return success;
}

int deleteItem(Node** pList, char* songTitleSrch) //** pList is to change pList, not the list's contents (that's *pList)
{
	Node* pCur = *pList, * pPrev = NULL;
	int success = 0;

	while (pCur != NULL && strcmp(pCur->record->song, songTitleSrch) != 0)
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

int promptForOption()
{
	int option = -1;
	
	printMenu();
	do
	{
		printf("Make your selection > ");
		scanf(" %d", &option);
	} while (option < 1 || option > 11);

	return option;
}

// create a new Node
Node* makeNode(char* artist, char* albumTitle, char* songTitle, char* genre, int minutes, int seconds, int timesPlayed, int rating)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	Record* newRec = (Record*)malloc(sizeof(Record));
	Duration* newDur = (Duration*)malloc(sizeof(Duration));

	if (newNode != NULL && newRec != NULL && newDur != NULL) // space allocated for Node, Record, and Duration
	{
		// populate strings in Record
		strcpy(newRec->artist, artist);
		strcpy(newRec->album, albumTitle);
		strcpy(newRec->song, songTitle);
		strcpy(newRec->genre, genre);

		// populate Duration then add it to the Record
		newDur->minutes = minutes;
		newDur->seconds = seconds;
		newRec->length = newDur;

		// populate ints in Record
		newRec->timesPlayed = timesPlayed;
		newRec->rating = rating;

		// add Record to Node and initialize pPrev and pNext
		newNode->record = newRec;
		newNode->pPrev = NULL;
		newNode->pNext = NULL;
	}
	return newNode;
}

void scanSongFile(FILE* infile, char* line, char* artist, char* albumTitle, char* songTitle, char* genre, int* minutes, int* seconds, int* timesPlayed, int* rating)
{
	strcpy(artist, strtok(line, ","));
	strcpy(albumTitle, strtok(NULL, ","));
	strcpy(songTitle, strtok(NULL, ","));
	strcpy(genre, strtok(NULL, ","));

	*minutes = strtok(NULL, ",:");
	*seconds = strtok(NULL, ",");
	*timesPlayed = strtok(NULL, ",");
	*rating = strtok(NULL, ",");
}

void printListRec(Node* pHead)
{
	if (pHead != NULL) // there is a movie to print, recursive step
	{
		printf("--> %s, %s, %s, %s, %d:%d, %d times, rating: %d", pHead->record->artist, pHead->record->album, pHead->record->song, pHead->record->genre, pHead->record->length->minutes, pHead->record->length->seconds, pHead->record->timesPlayed, pHead->record->rating); // arrow before to keep aesthetically clean
		printListRec(pHead->pNext); // pNext is address of next node
	}
	else // base case
	{
		printf(" -->\n");
	}
}

void setVarsToDefault(char *artist, char* album, char* song, char* genre, int* minutes, int* seconds, int* timesPlayed, int *rating)
{
	artist[0] = '\0';
	album[0] = '\0';
	song[0] = '\0';
	genre[0] = '\0';
	*minutes = 0;
	*seconds = 0;
	*timesPlayed = 0;
	*rating = 0;
}

void printMenu()
{
	printf("********** Music Playlist **********\n");
	printf("1. Load\n");
	printf("2. Store\n");
	printf("3. Display\n");
	printf("4. Insert\n");
	printf("5. Delete\n");
	printf("6. Edit\n");
	printf("7. Sort\n");
	printf("8. Rate\n");
	printf("9. Play\n");
	printf("10. Shuffle\n");
	printf("11. Exit\n");
}