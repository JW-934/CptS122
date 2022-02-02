/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA2
* Date: January 27, 2022, January 28, 2022, February 1, 2022
* Description: a basic digital music manager
*/

#include "PA2.h"

int main(void)
{
	FILE* infile = NULL;
	
	Node* pHead = NULL;

	int option = 0, numSongs = 0, minutes, seconds, timesPlayed, rating, success = 0;

	char line[100] = "", artist[20] = "", song[20] = "", genre[20] = "", album[20] = "";

	do
	{
		option = promptForOption();
		
		switch (option)
		{
		case 1: // load
			infile = fopen(INPUTFILE, "r");

			if (infile != NULL)
			{
				while (fgets(line, 100, infile) != NULL)
				{
					scanSongFile(infile, line, artist, album, song, genre, &minutes, &seconds, &timesPlayed, &rating);

					success = insertFront(&pHead, artist, album, song, genre, minutes, seconds, timesPlayed, rating);

					printListRec(pHead);

					setVarsToDefault(artist, album, song, genre, &minutes, &seconds, &timesPlayed, &rating);
				}
				fclose(infile);
			}
			break;
		case 2: // store

			break;

		case 3: // display

			break;
		case 4: // insert

			break;
		case 5: // delete

			break;
		case 6: // edit

			break;
		case 7: // sort

			break;
		case 8: // rate

			break;
		case 9: // play

			break;
		case 10: // shuffle

			break;
		case 11: // exit

			break;
		}
	} while (option != 11);


	return 0;
}