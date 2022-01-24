/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Programming Assignment: PA1
* Date: January 18, 2022, January 19, 2022, January 20, 2022, January 23, 2022
* Description: This program analyzes Fitbit data
*/

#include "PA1.h"

/* Name: spacesInEmptyFields
*  Preconditions:
*  Postconditions:
*  Description: 		
*/

void spacesInEmptyFields(char* str, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] == ',' && str[i + 1] == ',') // back to back commas (empty field)
		{
			for (int j = 0; j < length - i; j++)
			{
				str[(length - j) + 1] = str[length - j];
			}
			str[i + 1] = ' ';
		}
		if (str[i] == ',' && str[i + 1] == '\n') // comma at the end of a line (missing sleep level)
		{
			str[i + 1] = ' ';
			str[i + 2] = '/n';
		}
	}
	return;
}

void populateArray(FitbitData data[], int *lineCount, char line[], char target[])
{
	char currentToken[20] = "", invalid[] = "-1";
	
	// patient
	strcpy(currentToken, strtok(line, ","));
	if (currentToken[0] != ' ')
	{
		strcpy(data[*lineCount].patient, currentToken);
	}
	else
	{
		strcpy(data[*lineCount].patient, invalid);
	}
	printf("patient: %s\n", data[*lineCount].patient);

	currentToken[0] = '\0';

	// minute
	strcpy(currentToken, strtok(NULL, ","));
	if (currentToken[0] != ' ')
	{
		strcpy(data[*lineCount].minute, currentToken);
	}
	else
	{
		strcpy(data[*lineCount].minute, invalid);
	}
	printf("minute: %s\n", data[*lineCount].minute);

	currentToken[0] = '\0';

	// calories
	strcpy(currentToken, strtok(NULL, ","));
	if (currentToken[0] != ' ')
	{
		data[*lineCount].calories = atof(currentToken);
	}
	else
	{
		data[*lineCount].calories = -1;
	}
	printf("calories: %lf\n", data[*lineCount].calories);

	currentToken[0] = '\0';

	// distance
	strcpy(currentToken, strtok(NULL, ","));
	if (currentToken[0] != ' ')
	{
		data[*lineCount].distance = atof(currentToken);
	}
	else
	{
		data[*lineCount].distance = -1;
	}
	printf("distance: %lf\n", data[*lineCount].distance);

	currentToken[0] = '\0';

	// floors
	strcpy(currentToken, strtok(NULL, ","));
	if (currentToken[0] != ' ')
	{
		data[*lineCount].floors = atoi(currentToken);
	}
	else
	{
		data[*lineCount].floors = -1;
	}
	printf("floors: %d\n", data[*lineCount].floors);

	currentToken[0] = '\0';

	// heartrate
	strcpy(currentToken, strtok(NULL, ","));
	if (currentToken[0] != ' ')
	{
		data[*lineCount].heartRate = atoi(currentToken);
	}
	else
	{
		data[*lineCount].heartRate = -1;
	}
	printf("heart rate: %d\n", data[*lineCount].heartRate);

	currentToken[0] = '\0';

	// steps
	strcpy(currentToken, strtok(NULL, ","));
	if (currentToken[0] != ' ')
	{
		data[*lineCount].steps = atoi(currentToken);
	}
	else
	{
		data[*lineCount].steps = -1;
	}
	printf("steps: %d\n", data[*lineCount].steps);

	currentToken[0] = '\0';

	// sleep level
	strcpy(currentToken, strtok(NULL, ","));
	if (currentToken[0] != ' ')
	{
		data[*lineCount].sleepLevel = atoi(currentToken);
	}
	else
	{
		data[*lineCount].sleepLevel = -1;
	}
	printf("sleep level: %d\n", data[*lineCount].sleepLevel);

	putchar('\n');
}