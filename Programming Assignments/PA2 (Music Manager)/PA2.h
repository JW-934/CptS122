/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA2 and PA3
* Date: January 27, 2022, January 28, 2022, February 1, 2022, February 9, 2022, February 12, 2022
* Description: a basic digital music manager
*/

#ifndef PA2_H

#define PA2_H
#define _CRT_SECURE_NO_WARNINGS
#define INPUTFILE "testPlaylistOutput.csv"//"musicPlaylist.csv"
#define OUTPUTFILE "testPlaylistOutput.csv"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct duration
{
	int minutes;
	int seconds;
}Duration;

typedef struct record
{
	char artist[50];
	char album[50];
	char song[50];
	char genre[20];
	struct duration* length;
	int timesPlayed;
	int rating;
}Record;

typedef struct node
{
	struct record* record;
	struct node* pNext;
	struct node* pPrev;
}Node;

int insertFront(Node** pList, char* artist, char* albumTitle, char* songTitle, char* genre, int minutes, int seconds, int timesPlayed, int rating);
int deleteItem(Node** pList, char* songTitleSrch);
int promptForOption(int lowerBound, int upperBound);
//int promptForOption1or2(); // I just added parameters to the promptForOption() to eliminate this redundant one
int insertSong(Node** pList);

// Prompts for artist name, verifies that at least one corresponding node exists, sets value of how many of their songs are in the list
char* promptForArtist(Node* pHead, int* numSongs);
// Prompts for song name and verifies that at least one corresponding node exists
char* promptForSong(Node* pHead);

Node* makeNode(char* artist, char* albumTitle, char* songTitle, char* genre, int minutes, int seconds, int timesPlayed, int rating);

void printNodesByArtist(Node* pList, char* searchName);
void scanSongFile(FILE* infile, char* line, char* artist, char* albumTitle, char* songTitle, char* genre, int* minutes, int* seconds, int* timesPlayed, int* rating);
void printListRec(Node* pHead);
void setVarsToDefault(char* artist, char* album, char* song, char* genre, int* minutes, int* seconds, int* timesPlayed, int* rating);
void printMenu();
void printToFile(Node* pList, FILE* outfile);
void editSong(Node* pList);

// Precondition: artist confirmed to have at least one song in the list
void printAllFromArtist(Node* pList, char* artist);

// Precondition: artist confirmed to have at least one song in the list, song confirmed to exist in the list
void editRating(Node* pList, char* song, char* artist);
void deleteSong(Node** pHead);
#endif