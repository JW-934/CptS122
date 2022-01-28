/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA2
* Date: January 27, 2022, January 28, 2022
* Description:
*/

#ifndef PA2_H

#define PA2_H
#define _CRT_SECURE_NO_WARNINGS

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
	char name[20];
	Duration time;
}Record;


#endif
