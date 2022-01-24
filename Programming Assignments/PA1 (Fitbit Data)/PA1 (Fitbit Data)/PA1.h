/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Programming Assignment: PA1
* Date: January 18, 2022, January 19, 2022, January 20, 2022, January 23, 2022
* Description: This program analyzes Fitbit data
*/

#ifndef PA1_H

#define PA1_H
#define _CRT_SECURE_NO_WARNINGS
#define INPUTFILE "TestData.csv"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum sleep
{
    NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit
{
    char patient[10];
    char minute[9];
    double calories;
    double distance;
    unsigned int floors;
    unsigned int heartRate;
    unsigned int steps;
    Sleep sleepLevel;
} FitbitData;

///* Name: populateEmptyFields
//*  Preconditions: line[] must contain a line's worth of data from the input file, usableLine[] must be declared
//*  Postconditions: if a line was missing data, usableLine[] will be a version of said line with neutral values to be used
//*  Description: takes a copy of a line, compares each token to the null character, if null, replaces empty space with neutral value
//*/
//int populateEmptyFields(char* line[], char* usableLine[]);

void spacesInEmptyFields(char* str, int length);
//void insertInvalidValues(char* str);
void populateArray(FitbitData data[], int* lineCount, char line[]);
#endif