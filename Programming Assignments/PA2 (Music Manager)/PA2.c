/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA2 and PA3
* Date: January 27, 2022, January 28, 2022, February 1, 2022, February 9, 2022, February 12, 2022, February 13, 2022, February 14, 2022
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
		//else
		//{
		//	// empty
		//	(*pList)->pPrev = NULL; // doubly link
		//	newNode->pNext = NULL;
		//}
		*pList = newNode;
		success = 1;
	}
	return success;
}

int deleteItem(Node** pList, char* songTitleSrch, char* deleteArtist) //** pList is to change pList, not the list's contents (that's *pList)
{
	Node* pCur = *pList, * pPrev = NULL;
	int success = 0;

	songTitleSrch[strlen(songTitleSrch) - 1] = '\0'; // getting rid of \n from fgets
	deleteArtist[strlen(deleteArtist) - 1] = '\0'; // getting rid of \n from fgets

	//if (strcmp(artistSrch, "empty") == 0) // only one song in list with the target name
	//{
		while (pCur != NULL && (strcmp(pCur->record->song, songTitleSrch) != 0 || strcmp(pCur->record->artist, deleteArtist) != 0))
		{
			// move the pointers to correct position in list
			pPrev = pCur;
			pCur = pCur->pNext;
		}
		// guarantees we've positioned pointers correctly
		if (pCur != NULL)
		{
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
	//}
	//else
	//{
	//	while (pCur != NULL && strcmp(pCur->record->song, songTitleSrch) != 0 && strcmp(pCur->record->artist, artistSrch) != 0)
	//	{
	//		// move the pointers to correct position in list
	//		pPrev = pCur;
	//		pCur = pCur->pNext;
	//	}
	//	// guarantees we've positioned pointers correctly
	//	if (pCur != NULL)
	//	{
	//		success = 1;

	//		if (pPrev == NULL)
	//		{
	//			// removing the first node
	//			// *pList = pCur
	//			*pList = pCur->pNext; // (* pList)->pNext;
	//		}
	//		else
	//		{
	//			// removing a node after the first one -- end/last node/middle
	//			// pPrev not null
	//			pPrev->pNext = pCur->pNext;
	//		}
	//		free(pCur);
	//	}
	//}
	return success;
}

int promptForOption(int lowerBound, int upperBound)
{
	int option = -1;
	
	do
	{
		printf("Make your selection > ");
		scanf(" %d", &option);
	} while (option < lowerBound || option > upperBound || option == 0); // reprompt until valid option value entered

	return option;
}

//int promptForOption1or2()
//{
//	int option = -1;
//
//	do
//	{
//		printf("Make your selection > ");
//		scanf(" %d", &option);
//	} while (option < 1 || option > 2 || option == 0); // reprompt until valid option value entered
//
//	return option;
//}

int insertSong(Node** pList)
{
	int insertMinutes = -1, insertSeconds = -1, insertTimes = 0, insertRating = -1;
	char insertArtist[50] = "", insertSong[20] = "", insertGenre[20] = "", insertAlbum[20] = "";
	
	// Prompts for artist
	printf("Enter the name of the artist > ");
	getchar();
	fgets(insertArtist, 50, stdin);
	insertArtist[strlen(insertArtist) - 1] = '\0'; // These are to eliminate the \n at the end of the strings from the fgets
	
	// Prompts for album
	printf("Enter the name of the album > ");
	//getchar();
	fgets(insertAlbum, 50, stdin);
	insertAlbum[strlen(insertAlbum) - 1] = '\0';
	
	// Prompts for song
	printf("Enter the name of the song > ");
	//getchar();
	fgets(insertSong, 50, stdin);
	insertSong[strlen(insertSong) - 1] = '\0';
	
	// Prompts for genre
	printf("Enter the genre of the song > ");
	//getchar();
	fgets(insertGenre, 50, stdin);
	insertGenre[strlen(insertGenre) - 1] = '\0';

	// Prompts for length
	do
	{
		printf("Enter the song length (M:S) > ");
		scanf("%d:%d", &insertMinutes, &insertSeconds);
	} while (insertMinutes < 0 || insertSeconds < 0);
	
	// turns seconds >= 60 into minutes
	if (insertSeconds >= 60)
	{
		while (insertSeconds >= 60)
		{
			++insertMinutes;
			insertSeconds -= 60;
		}
	}
	
	// Prompts for rating
	do
	{
		printf("Enter the song rating (1-5) > ");
		scanf("%d", &insertRating);
	} while (insertRating < 1 || insertRating > 5);

	return insertFront(pList, insertArtist, insertAlbum, insertSong, insertGenre, insertMinutes, insertSeconds, insertTimes, insertRating);
	
	/*insertArtist[0] = '\0', insertAlbum[0] = '\0', insertSong[0] = '\0', insertGenre[0] = '\0';
	insertMinutes = 0, insertSeconds = 0, insertTimes = 0, insertRating = 0;*/
}

// Prompts for artist name, verifies that at least one corresponding node exists, sets value of how many of their songs are in the list
char* promptForArtist(Node* pHead, int* numSongs)
{
	int exists = 0;
	char search[50] = "", curStr[50] = "";
	Node* pCur = pHead;
	if (pCur != NULL)
	{
		do
		{
			printf("\nEnter an artist > ");
			
			//getchar();
			fgets(search, 50, stdin);

			while (pCur != NULL) // finds first song by target artist ; && exists == 0
			{
				strcpy(curStr, pCur->record->artist);
				strcat(curStr, "\n"); // have to add newline to match the one that comes from the fgets
				if (strcmp(curStr, search) == 0)
				{
					exists = 1;
					++*numSongs;
				}
				pCur = pCur->pNext;
				curStr[0] = '\0';
			}
			if (pCur = NULL && exists == 0)
			{
				printf("\nArtist not found!\n");
			}
		} while (exists == 0);
		//while (pCur != NULL && exists == 1) // counts rest of the artist's songs
		//{
		//	strcpy(curStr, pCur->record->artist);
		//	strcat(curStr, "\n"); // have to add newline to match the one that comes from the fgets
		//	if (strcmp(curStr, search) == 0)
		//	{
		//		++*numSongs;
		//	}
		//}
		if (exists == 1)
		{
			return search;
		}
	}
}

// Prompts for song name and verifies that at least one corresponding node exists, sets value of how many of their songs there are with the same name
char* promptForSong(Node* pHead, int* numSongs)
{
	int exists = 0;
	char search[50] = "", curStr[50] = "";
	Node* pCur = pHead;
	if (pCur != NULL)
	{
		do
		{
			printf("\nEnter a song > ");

			getchar();
			fgets(search, 50, stdin);

			while (pCur != NULL)
			{
				strcpy(curStr, pCur->record->song);
				strcat(curStr, "\n"); // have to add newline to match the one that comes from the fgets
				if (strcmp(curStr, search) == 0)
				{
					exists = 1;
					++*numSongs;
				}
				pCur = pCur->pNext;
				curStr[0] = '\0';
			}
			if (pCur = NULL && exists == 0)
			{
				printf("\nSong not found!\n");
			}
		} while (exists == 0);
		if (exists == 1)
		{
			return search;
		}
	}
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

void printNodesByArtist(Node* pList, char* searchName)
{
	Node* pCur = pList, *targetNode = NULL;

	if (pCur != NULL)
	{
		while (pCur != NULL)
		{
			if (strcmp(pCur->record->artist, searchName) == 0)
			{
				printf("--> %s, %s, %s, %s, %d:%d, %d Plays, %d Star Rating\n", pCur->record->artist, pCur->record->album, pCur->record->song, pCur->record->genre, pCur->record->length->minutes, pCur->record->length->seconds, pCur->record->timesPlayed, pCur->record->rating);
			}
			pCur = pCur->pNext;
		} 
	}
}

void scanSongFile(FILE* infile, char* line, char* artist, char* albumTitle, char* songTitle, char* genre, int* minutes, int* seconds, int* timesPlayed, int* rating)
{
	char firstName[15] = "", lastName[15] = "";
	if (line[0] == '"') // artist with full name
	{
		strcpy(lastName, strtok(line, ","));
		strcpy(firstName, strtok(NULL, ","));

		// replace double quotes with spaces
		lastName[0] = ' ';
		firstName[strlen(firstName) - 1] = ' ';

		// move last name back by one space to eliminate extra space before names
		for (int i = 0; i < strlen(firstName); ++i)
		{
			firstName[i] = firstName[i + 1];
		}

		// move last name back by one space to eliminate extra space between names
		for (int j = 0; j < strlen(lastName); ++j)
		{
			lastName[j] = lastName[j + 1];
		}

		// put names together in artist string
		strcpy(artist, firstName);
		strcat(artist, lastName);
		
		//// move characters in artist string over to eliminate extra spaces
		//for (int i = 0; i < strlen(artist); ++i)
		//{
		//	artist[i] = artist[i + 1];
		//}

		//// move last name back by one space to eliminate extra space between names
		//for (int j = strlen(firstName) + 1; j < strlen(artist); ++j)
		//{
		//	artist[j] = artist[j + 1];
		//}

		/*strcpy(artist, strtok(line, ","));
		strcat(artist, strtok(NULL, ","));*/
	}
	else // artist with one name
	{
		strcpy(artist, strtok(line, ","));
	}
	strcpy(albumTitle, strtok(NULL, ","));
	strcpy(songTitle, strtok(NULL, ","));
	strcpy(genre, strtok(NULL, ","));

	*minutes = atoi(strtok(NULL, ":"));
	*seconds = atoi(strtok(NULL, ","));
	*timesPlayed = atoi(strtok(NULL, ","));
	*rating = atoi(strtok(NULL, ","));
}

void printListRec(Node* pHead)
{
	if (pHead != NULL) 
	{
		if (pHead->record->length->seconds < 10)
		{
			printf("%s, %s, %s, %s, %d:0%d, %d Plays, %d Star Rating\n", pHead->record->artist, pHead->record->album, pHead->record->song, pHead->record->genre, pHead->record->length->minutes, pHead->record->length->seconds, pHead->record->timesPlayed, pHead->record->rating);
		}
		else
		{
			printf("%s, %s, %s, %s, %d:%d, %d Plays, %d Star Rating\n", pHead->record->artist, pHead->record->album, pHead->record->song, pHead->record->genre, pHead->record->length->minutes, pHead->record->length->seconds, pHead->record->timesPlayed, pHead->record->rating);
		}
		printListRec(pHead->pNext); // pNext is address of next node
	}
	else // base case
	{
		printf("\n");
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
	printf("*                                  *\n");
	printf("*            1.  Load              *\n");
	printf("*            2.  Store             *\n");
	printf("*            3.  Display           *\n");
	printf("*            4.  Insert            *\n");
	printf("*            5.  Delete            *\n");
	printf("*            6.  Edit              *\n");
	printf("*            7.  Sort              *\n");
	printf("*            8.  Rate              *\n");
	printf("*            9.  Play              *\n");
	printf("*            10. Shuffle           *\n");
	printf("*            11. Exit              *\n");
	printf("*                                  *\n");
	printf("************************************\n");
}

void printToFile(Node* pHead, FILE* outfile)
{
	Node* pCur = pHead;
	if (pHead != NULL)
	{
		while (pCur != NULL)
		{
			fprintf(outfile, "%s,%s,%s,%s,%d:%d,%d,%d\n", pCur->record->artist, pCur->record->album, pCur->record->song, pCur->record->genre, pCur->record->length->minutes, pCur->record->length->seconds, pCur->record->timesPlayed, pCur->record->rating);
			pCur = pCur->pNext;
		}
		printf("Playlist stored to file!");
	}
	else 
	{
		printf("Could not open playlist file!");
	}
}

// Precondition: artist confirmed to have at least one song in the list
void printAllFromArtist(Node* pList, char* artist)
{
	Node* pCur = pList;
	char curStr[50] = "";

	while (pCur != NULL)
	{
		strcpy(curStr, pCur->record->artist);
		strcat(curStr, "\n");
		if (strcmp(curStr, artist) == 0)
		{
			if (pCur->record->length->seconds < 10)
			{
				printf("%s, %s, %s, %s, %d:0%d, %d Plays, %d Star Rating\n", pCur->record->artist, pCur->record->album, pCur->record->song, pCur->record->genre, pCur->record->length->minutes, pCur->record->length->seconds, pCur->record->timesPlayed, pCur->record->rating);
			}
			else
			{
				printf("%s, %s, %s, %s, %d:%d, %d Plays, %d Star Rating\n", pCur->record->artist, pCur->record->album, pCur->record->song, pCur->record->genre, pCur->record->length->minutes, pCur->record->length->seconds, pCur->record->timesPlayed, pCur->record->rating);
			}
		}
		pCur = pCur->pNext;
	}
	putchar('\n');
}

// Precondition: artist confirmed to have at least one song in the list, song confirmed to exist in the list
void editRating(Node* pList, char* song, char* artist)
{
	Node* pCur = pList;
	char curArtist[50] = "", curSong[50];
	int newRating = 0;

	while (pCur != NULL)
	{
		strcpy(curArtist, pCur->record->artist);
		strcat(curArtist, "\n");
		strcpy(curSong, pCur->record->song);
		strcat(curSong, "\n");

		if (strcmp(curArtist, artist) == 0 && strcmp(curSong, song) == 0) // Target song found
		{
			printf("Songs can be rated 1 to 5 stars.\n");
			newRating = promptForOption(1, 5);

			pCur->record->rating = newRating;
		}
		pCur = pCur->pNext;
	}
	putchar('\n');
}

void editSong(Node* pList)
{
	int numSongs = 0, songFound = 0, artistFound = 0, discard = 0;
	char editArtist[20] = "", editSong[20] = "";
	Node* pCur = pList;

	// Variables from insertSong()
	int insertMinutes = -1, insertSeconds = -1, insertTimes = -1, insertRating = -1;
	char insertArtist[50] = "", insertSong[20] = "", insertGenre[20] = "", insertAlbum[20] = "";
	
	strcpy(editArtist, promptForArtist(pList, &numSongs));
	editArtist[strlen(editArtist) - 1] = '\0'; // getting rid of \n from fgets
	
	if (numSongs > 1) // multiple songs by artist
	{
		strcpy(editSong, promptForSong(pList, &discard));
		editSong[strlen(editSong) - 1] = '\0'; // getting rid of \n from fgets

		while (songFound == 0) // sets pCur to target song
		{
			if (strcmp(editSong, pCur->record->song) == 0)
			{
				songFound = 1;
			}
			else
			{
				pCur = pCur->pNext;
			}
		}
	}
	else // only one song by artist
	{
		while (artistFound == 0) // sets pCur to target song
		{
			if (strcmp(editArtist, pCur->record->artist) == 0)
			{
				artistFound = 1;
			}
			else
			{
				pCur = pCur->pNext;
			}
		}
	}
	// pCur now set to target node
	
	// Below is altered insertSong()

	// Prompts for artist
	printf("\nEnter the new artist name > ");
	//getchar();
	fgets(insertArtist, 50, stdin);
	insertArtist[strlen(insertArtist) - 1] = '\0'; // These are to eliminate the \n at the end of the strings from the fgets

	// Prompts for album
	printf("\nEnter the new album name > ");
	//getchar();
	fgets(insertAlbum, 50, stdin);
	insertAlbum[strlen(insertAlbum) - 1] = '\0';

	// Prompts for song
	printf("\nEnter the new song name > ");
	//getchar();
	fgets(insertSong, 50, stdin);
	insertSong[strlen(insertSong) - 1] = '\0';

	// Prompts for genre
	printf("\nEnter the new genre > ");
	//getchar();
	fgets(insertGenre, 50, stdin);
	insertGenre[strlen(insertGenre) - 1] = '\0';

	// Prompts for length
	do
	{
		printf("\nEnter the new song length (M:S) > ");
		scanf("%d:%d", &insertMinutes, &insertSeconds);
	} while (insertMinutes < 0 || insertSeconds < 0);

	// turns seconds >= 60 into minutes
	if (insertSeconds >= 60)
	{
		while (insertSeconds >= 60)
		{
			++insertMinutes;
			insertSeconds -= 60;
		}
	}
	
	// Prompts for times played
	do
	{
		printf("\nEnter the new amount of times the song has been played > ");
		scanf("%d", &insertTimes);
	} while (insertTimes < 0);

	// Prompts for rating
	do
	{
		printf("\nEnter the new song rating (1-5) > ");
		scanf("%d", &insertRating);
	} while (insertRating < 1 || insertRating > 5);

	// Inserts new values into the target node
	strcpy(pCur->record->artist, insertArtist);
	strcpy(pCur->record->album, insertAlbum);
	strcpy(pCur->record->song, insertSong);
	strcpy(pCur->record->genre, insertGenre);
	pCur->record->length->minutes = insertMinutes;
	pCur->record->length->seconds = insertSeconds;
	pCur->record->timesPlayed = insertTimes;
	pCur->record->rating = insertRating;

	putchar('\n'); 
}

void playRestOfList(Node* pList, char* startSongName, char* startArtistName)
{
	Node* pCur = pList, * pPrev = NULL;
	int success = 0;

	if (strcmp(startSongName, "") == 0) // starting from top of list
	{
		while (pCur->pNext != NULL)
		{
			system("cls");
			printf("Playing %s by %s.", pCur->record->song, pCur->record->artist);
			Sleep(500);
			pCur = pCur->pNext;
		}
	}
	else // starting from particular song
	{
		startSongName[strlen(startSongName) - 1] = '\0'; // getting rid of \n from fgets
		startArtistName[strlen(startArtistName) - 1] = '\0'; // getting rid of \n from fgets

		while (pCur != NULL && (strcmp(pCur->record->song, startSongName) != 0 || strcmp(pCur->record->artist, startArtistName) != 0))
		{
			// move the pointers to correct position in list
			pPrev = pCur;
			pCur = pCur->pNext;
		}
		while (pCur != NULL)
		{
			system("cls");
			printf("Playing %s by %s.", pCur->record->song, pCur->record->artist);
			Sleep(500);
			pCur = pCur->pNext;
		}
	}
}