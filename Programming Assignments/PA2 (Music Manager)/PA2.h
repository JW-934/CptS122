/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA2
* Date: January 27, 2022, January 28, 2022, February 1, 2022
* Description: a basic digital music manager
*/

#ifndef PA2_H

#define PA2_H
#define _CRT_SECURE_NO_WARNINGS
#define INPUTFILE "musicPlaylist.csv"

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
int promptForOption();

Node* makeNode(char* artist, char* albumTitle, char* songTitle, char* genre, int minutes, int seconds, int timesPlayed, int rating);

void scanSongFile(FILE* infile, char* line, char* artist, char* albumTitle, char* songTitle, char* genre, int* minutes, int* seconds, int* timesPlayed, int* rating);
void printListRec(Node* pHead);
void setVarsToDefault(char* artist, char* album, char* song, char* genre, int* minutes, int* seconds, int* timesPlayed, int* rating);
void printMenu();
#endif