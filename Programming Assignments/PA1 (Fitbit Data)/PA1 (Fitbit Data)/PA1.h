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
    int floors;
    int heartRate;
    int steps;
    Sleep sleepLevel;
} FitbitData;

/* Name: spacesInEmptyFields
*  Preconditions:
*  Postconditions:
*  Description: 
*/

void spacesInEmptyFields(char* str, int length);
void populateArray(FitbitData data[], int* lineCount, char line[], char target[]);
#endif