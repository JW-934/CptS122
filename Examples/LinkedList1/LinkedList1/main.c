/*
Programmer: Jesse Watson
Date: January 21, 2022
Class: Cpt_S 122 Spring 2022
Description: Example of a linked list
*/

#include "linkedlist1.h"

int main(int argc, char *argv[])
{
	Node* pHead = NULL; // empty list - initList would set head to NULL

	pHead = makeNode("Inception", 2006); // hardcoded not maintainable

	printf("first movie: title: %s, year: %d\n", pHead->movieTitle, pHead->year);

	return 0;
}