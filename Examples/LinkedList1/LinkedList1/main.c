/*
Programmer: Jesse Watson
Date: January 21, 2022, January 24, 2022, January 26, 2022
Class: Cpt_S 122 Spring 2022
Description: Example of a linked list
*/

#include "linkedlist1.h"

int main(int argc, char *argv[])
{
	Node* pHead = NULL; // empty list - initList would set head to NULL
	int success = 0;

	//pHead = makeNode("Inception", 2006); // hardcoded not maintainable

	//printf("first movie: title: %s, year: %d\n", pHead->movieTitle, pHead->year);

	/*success = insertFront(&pHead, "Inception", 2006);
	success = insertFront(&pHead, "Spiderman", 2021);
	success = insertFront(&pHead, "Star Wars", 2006);
	success = insertFront(&pHead, "BTF", 1986);*/

	success = insertInOrder(&pHead, "BTF", 1986);
	success = insertInOrder(&pHead, "Alien", 1986);
	success = insertInOrder(&pHead, "Spiderman", 2021);
	success = insertInOrder(&pHead, "Inception", 2006);

	printListRec(pHead);

	return 0;
}