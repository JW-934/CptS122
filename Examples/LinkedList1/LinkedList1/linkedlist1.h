/*
Programmer: Jesse Watson
Date: January 21, 2022
Class: Cpt_S 122 Spring 2022
Description: Example of a linked list
*/

#ifndef LINKEDLIST1_H
#define LINKEDLIST1_H // if something already included in project, don't include twice

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> //malloc(), calloc(), free()
#include <string.h>

// malloc(sizeof (int * 10): array
// calloc(sizeof (int), 10): initialized array (to default values)

typedef struct node 
{
	// movies
	char movieTitle[50]; // 50 bytes // char * would require dynamic memory
	int year; // 4 bytes
	
	// link
	struct node* pNext; // generally 4 bytes
}Node; // 58 bytes

Node* makeNode(char *newMovieTitle, int newYear); // passing by array name -->char *

int insertFront(Node **pList, char* newMovieTitle, int newYear);

void printListRec(Node *pHead); // not changing head pointer so not Node **
#endif