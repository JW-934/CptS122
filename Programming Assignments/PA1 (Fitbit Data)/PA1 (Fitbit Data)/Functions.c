/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Programming Assignment: PA1
* Date: January 18, 2022, January 19, 2022, January 20, 2022
* Description: This program analyzes Fitbit data
*/

#include "PA1.h"

/* Name: populateEmptyFields
*  Preconditions: line[] must contain a line's worth of data from the input file, usableLine[] must be declared
*  Postconditions: if a line was missing data, usableLine[] will be a version of said line with neutral values to be used
*  Description: takes a copy of a line, compares each token to the null character, if not null, concatenates value into
*				usableLine[], if null, concatenates neutral value into usableLine[].
*/
int populateEmptyFields(char* line[], char* usableLine[])
{
	char invalidID[] = "AAAAA", invalid[] = "-1", invalidTime[] = "-1:00:00", comma[] = ",",lineCopy[100] = "", lineCopy2[100] = "", token[20] = "";

	usableLine[0] = '\0';

	strcpy(lineCopy, line);
	strcpy(lineCopy2, line);

	// patient
	if (strtok(lineCopy, ",") == NULL)
	{
		strcat(usableLine, invalidID);
		strcat(usableLine, comma);
		strcpy(token, strtok(lineCopy2, ","));
	}
	else
	{
		strcpy(token, strtok(lineCopy2, ","));
		strcat(usableLine, token);
		strcat(usableLine, comma);
	}
	token[0] = '\0';
	// minute
	if (strtok(NULL, ",") == NULL)
	{
		strcat(usableLine, invalidTime);
		strcat(usableLine, comma);
		strcpy(token, strtok(lineCopy2, ","));
	}
	else
	{
		strcpy(token, strtok(lineCopy2, ","));
		strcat(usableLine, token);
		strcat(usableLine, comma);
	}
	token[0] = '\0';
	// calories
	if (strtok(NULL, ",") == NULL)
	{
		strcat(usableLine, invalid);
		strcat(usableLine, comma);
		strcpy(token, strtok(lineCopy2, ","));
	}
	else
	{
		strcpy(token, strtok(lineCopy2, ","));
		strcat(usableLine, token);
		strcat(usableLine, comma);
	}
	token[0] = '\0';
	// distance
	if (strtok(NULL, ",") == NULL)
	{
		strcat(usableLine, invalid);
		strcat(usableLine, comma);
		strcpy(token, strtok(lineCopy2, ","));
	}
	else
	{
		strcpy(token, strtok(lineCopy2, ","));
		strcat(usableLine, token);
		strcat(usableLine, comma);
	}
	token[0] = '\0';
	// floors
	if (strtok(NULL, ",") == NULL)
	{
		strcat(usableLine, invalid);
		strcat(usableLine, comma);
		strcpy(token, strtok(lineCopy2, ","));
	}
	else
	{
		strcpy(token, strtok(lineCopy2, ","));
		strcat(usableLine, token);
		strcat(usableLine, comma);
	}
	token[0] = '\0';
	// heartrate
	if (strtok(NULL, ",") == NULL)
	{
		strcat(usableLine, invalid);
		strcat(usableLine, comma);
		strcpy(token, strtok(lineCopy2, ","));
	}
	else
	{
		strcpy(token, strtok(lineCopy2, ","));
		strcat(usableLine, token);
		strcat(usableLine, comma);
	}
	token[0] = '\0';
	// steps
	if (strtok(NULL, ",") == NULL)
	{
		strcat(usableLine, invalid);
		strcat(usableLine, comma);
		strcpy(token, strtok(lineCopy2, ","));
	}
	else
	{
		strcpy(token, strtok(lineCopy2, ","));
		strcat(usableLine, token);
		strcat(usableLine, comma);
	}
	token[0] = '\0';
	// sleep lvl
	if (strtok(NULL, ",") == NULL)
	{
		strcat(usableLine, invalid);
		strcat(usableLine, comma);
		strcpy(token, strtok(lineCopy2, ","));
	}
	else
	{
		strcpy(token, strtok(lineCopy2, ","));
		strcat(usableLine, token);
	}
	token[0] = '\0';

	return 0;
}