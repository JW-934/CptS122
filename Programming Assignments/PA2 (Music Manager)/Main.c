/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA2 and PA3
* Date: January 27, 2022, January 28, 2022, February 1, 2022, February 9, 2022, February 12, 2022, February 13, 2022, February 14, 2022
* Description: a basic digital music manager
*/

#include "PA2.h"

int main(void)
{
	FILE* infile = NULL, * outfile = NULL;

	Node* pHead = NULL;

	int option = -1, numSongs = 0, minutes, seconds, timesPlayed, rating, success = 0, displayOption = -1, newRating = 0, insertSuccess = 0, discarded = 0, playOption = -1, deleteSuccess = 0, deleteNumSongs = 0;

	char line[100] = "", artist[20] = "", song[20] = "", genre[20] = "", album[20] = "", displaySearch[50] = "", rateArtist[50] = "", rateSong[50] = "", deleteArtist[20] = "empty", deleteSong[20] = "";

	do
	{
		printMenu();
		option = promptForOption(1, 11);
		
		switch (option)
		{
		case 1: // load /////////////////////////////////////////////////////////////////////////////////////////////////////
			infile = fopen(INPUTFILE, "r");

			system("cls");

			if (infile != NULL)
			{
				while (fgets(line, 100, infile) != NULL)
				{
					scanSongFile(infile, line, artist, album, song, genre, &minutes, &seconds, &timesPlayed, &rating);

					success = insertFront(&pHead, artist, album, song, genre, minutes, seconds, timesPlayed, rating);			

					setVarsToDefault(artist, album, song, genre, &minutes, &seconds, &timesPlayed, &rating);
				}
				fclose(infile);
				printf("Playlist loaded!\n\n");
			}
			else
			{
				printf("Could not open playlist file!\n\n");
			}
			break;
		case 2: // store ////////////////////////////////////////////////////////////////////////////////////////////////////////
			outfile = fopen(OUTPUTFILE, "w");
			
			system("cls");
			
			if (outfile != NULL)
			{
				printToFile(pHead, outfile);
			}
			else
			{
				printf("Could not open playlist file!\n\n");
			}
			fclose(outfile);
			break;
		case 3: // display /////////////////////////////////////////////////////////////////////////////////////////////////////
			
			printf("\n1. Display all songs\n2. Display all songs by a particular artist\n\n");

			displayOption = promptForOption(1, 2);
			
			if (displayOption == 1)
			{
				system("cls");

				printListRec(pHead);
			}
			else
			{
				strcpy(displaySearch, promptForArtist(pHead, &discarded));

				putchar('\n');
				
				printAllFromArtist(pHead, displaySearch);
			}
			break;
		case 4: // insert /////////////////////////////////////////////////////////////////////////////////////////////////////
			insertSuccess = insertSong(&pHead);
			break;
		case 5: // delete ///////////////////////////////////////////////////////////////////////////////////////////////////// I wanted to have it only prompt for artist if there were more than one song with the same name but I'm out of time
			system("cls");

			printListRec(pHead);
			
			strcpy(deleteSong, promptForSong(pHead, &deleteNumSongs));
			strcpy(deleteArtist, promptForArtist(pHead, &discarded));
			

			deleteSuccess = deleteItem(&pHead, deleteSong, deleteArtist);

			if (deleteSuccess == 1)
			{
				printf("\nSong has been deleted!\n\n");
			}
			else
			{
				printf("\nSong could not be deleted!\n\n");
			}
			break;
		case 6: // edit /////////////////////////////////////////////////////////////////////////////////////////////////////
			system("cls");

			printListRec(pHead);
			
			editSong(pHead);

			printf("Edits have been made!\n");

			break;
		case 7: // sort /////////////////////////////////////////////////////////////////////////////////////////////////////
			
			break;
		case 8: // rate /////////////////////////////////////////////////////////////////////////////////////////////////////
			strcpy(rateArtist, promptForArtist(pHead, &discarded));
			strcpy(rateSong, promptForSong(pHead, &discarded));

			editRating(pHead, rateSong, rateArtist);
			printf("Rating has been updated!\n");
			break;
		case 9: // play ///////////////////////////////////////////////////////////////////////////////////////////////////// I wanted to have it only prompt for artist if there were more than one song with the same name but I'm out of time
			printf("\n1. Play all songs\n2. Play starting at a certain song\n\n");

			playOption = promptForOption(1, 2);
			if (playOption == 1)
			{
				playRestOfList(pHead, "", "");

				printf("\nEnd of playlist.\n");
			}
			else
			{
				
			}
			break;
		case 10: // shuffle /////////////////////////////////////////////////////////////////////////////////////////////////////
			
			break;
		case 11: // exit /////////////////////////////////////////////////////////////////////////////////////////////////////
			break;
		}
	} while (option != 11);
	return 0;
}