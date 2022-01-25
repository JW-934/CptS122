/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Programming Assignment: PA1
* Date: January 18, 2022, January 19, 2022, January 20, 2022, January 23, 2022, January 24, 2022, January 25, 2022
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

/* Name: starsInEmptyFields()
*  Preconditions: line populated with strtok
*  Postconditions: any empty fields in the line will be have a star inserted
*/
void starsInEmptyFields(char* str, int length);

/* Name: populateArray()
*  Preconditions: line cleaned with spacesInEmptyFields(), line verified to have target patient ID
*  Postconditions: structs in data[] will be populated with information by the minute, any empty fields set to -1
*/
void populateArray(FitbitData data[], int* lineCount, char line[], char target[]);
#endif