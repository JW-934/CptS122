/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA2 and PA3
* Date: January 27, 2022, January 28, 2022, February 1, 2022, February 9, 2022, February 12, 2022, February 13, 2022, February 14, 2022
* Description: a basic digital music manager
*/

#include "PA2.h"
#include "Tests.h"

// Everything is working for the most part, shuffle generates a random order but sometimes passes in a NULL pointer, I am out of time to debug it.

int main(void)
{
	srand(time(0));
	
	FILE* infile = NULL, * outfile = NULL;

	Node* pHead = NULL, *shufflePcur = NULL, *shuffleSong = NULL, *settingBackwardPcur = NULL;

	int option = -1, numSongs = 0, minutes, seconds, timesPlayed, rating, success = 0, displayOption = -1, newRating = 0, insertSuccess = 0, discarded = 0, playOption = -1, deleteSuccess = 0, deleteNumSongs = 0, sortOption = 0, curRand, sameRand = 1, randIndex = 0, prevRand = 0, forwardIndex = 1, backwardIndex = 0, randIndex2 = 0;
	int random[50] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	
	char line[100] = "", artist[20] = "", song[20] = "", genre[20] = "", album[20] = "", displaySearch[50] = "", rateArtist[50] = "", rateSong[50] = "", deleteArtist[20] = "empty", deleteSong[20] = "", playArtist[20] = "", playSong[20] = "";

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

					++numSongs;
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
			printf("\n1. Sort based on artist (A-Z)\n2. Sort based on album title (A-A)\n3. Sort based on rating (1-5)\n4. Sort based on times played (largest-smallest)\n\n");
			
			sortOption = promptForOption(1, 4);

			switch (sortOption)
			{
			case 1: // artist sort // I'd like to make this more robust but I have little time left, I think 20 passes is fair for this use
				artistBubbleSort(pHead);

				system("cls");
				printf("Playlist sorted by artist!\n\n");

				printListRec(pHead);

				break;
			case 2: // album sort // I'd like to make this more robust but I have little time left, I think 20 passes is fair for this use
				albumBubbleSort(pHead);

				system("cls");
				printf("Playlist sorted by album!\n\n");

				printListRec(pHead);
				break;
			case 3: // rating sort
				ratingBubbleSort(pHead);

				system("cls");
				printf("Playlist sorted by rating!\n\n");

				printListRec(pHead);
				break;
			case 4: // times played sort
				timesBubbleSort(pHead);

				system("cls");
				printf("Playlist sorted by times played!\n\n");

				printListRec(pHead);
				break;
			}
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

				printf("End of playlist.\n");
			}
			else
			{
				system("cls");

				printListRec(pHead);

				strcpy(playSong, promptForSong(pHead, &deleteNumSongs));
				strcpy(playArtist, promptForArtist(pHead, &discarded));

				playRestOfList(pHead, playSong, playArtist);

				system("cls");
				printf("\nEnd of playlist.\n");
			}
			break;
		case 10: // shuffle /////////////////////////////////////////////////////////////////////////////////////////////////////
			for (int i = 0; i < numSongs; ++i) // populates numSongs number of elements in random[] with non repeating random numbers between 1 and numSongs
			{
				do
				{
					sameRand = 0;
					
					curRand = rand() % (numSongs)+1; // generates number between 1 and numSongs 

					randIndex = 0;

					for (; randIndex < numSongs; ++randIndex) // checks if random number is a duplicate
					{
						if (random[randIndex] != curRand)
						{
							//sameRand = 0;
						}
						else
						{
							sameRand = 1;
						}
					}

				} while (sameRand == 1);
				random[i] = curRand;
			}
			randIndex = 0;
			curRand = 0;
			backwardIndex = numSongs + 1;
			/*for (int j = 0; j < 50; ++j)
			{
				printf("%d ", random[j]);
			}*/
			/////////////////////// after this point random[] is populated correctly, bounded at end by -1 //////////////////////////////////
			shufflePcur = pHead;
			for (; randIndex < numSongs - 1; ++randIndex)
			{
				
				curRand = random[randIndex2];
				//shufflePcur = pHead;
				if (curRand > prevRand) // moving forward
				{
					shufflePcur = pHead;
					for (; forwardIndex <= curRand; ++forwardIndex)
					{
						shufflePcur = shufflePcur->pNext;
					}
				}
				else // moving backward
				{
					while (shufflePcur->pNext != NULL) // puts shufflePcur at last node
					{
						shufflePcur = shufflePcur->pNext;
					}
					for (; backwardIndex >= curRand + 1; --backwardIndex) // moves shufflePcur back to desired node
					{
						shufflePcur = shufflePcur->pPrev;
					}
				}
				shuffleSong = shufflePcur;
				prevRand = curRand;
				//forwardIndex = prevRand;
				forwardIndex = 1;
				backwardIndex = numSongs;
				++randIndex2;
				playOneSong(shuffleSong);
			}
			system("cls");
			printf("End of playlist.\n");
			break;
		case 11: // exit /////////////////////////////////////////////////////////////////////////////////////////////////////
			break;
		}
	} while (option != 11);
	return 0;
}