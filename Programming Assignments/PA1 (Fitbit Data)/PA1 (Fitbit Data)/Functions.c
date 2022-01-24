/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Programming Assignment: PA1
* Date: January 18, 2022, January 19, 2022, January 20, 2022, January 23, 2022
* Description: This program analyzes Fitbit data
*/

#include "PA1.h"

///* Name: populateEmptyFields
//*  Preconditions: line[] must contain a line's worth of data from the input file, usableLine[] must be declared
//*  Postconditions: if a line was missing data, usableLine[] will be a version of said line with neutral values to be used
//*  Description: takes a copy of a line, compares each token to the null character, if not null, concatenates value into
//*				usableLine[], if null, concatenates neutral value into usableLine[].
//*/
//int populateEmptyFields(char* line[], char* usableLine[])
//{
//	char invalidID[] = "AAAAA", invalid[] = "-1", invalidTime[] = "-1:00:00", comma[] = ",",lineCopy[100] = "", lineCopy2[100] = "", token[20] = "";
//
//	usableLine[0] = '\0';
//
//	strcpy(lineCopy, line);
//	//strcpy(lineCopy2, line);
//
//	// patient
//	//if (strtok(lineCopy, ",") == NULL) // Field is empty
//
//	strcpy(token, strtok(lineCopy, ","));
//	if (strcmp(token, "\0") == 0) // Field is empty
//	{
//		strcat(usableLine, invalidID);
//		strcat(usableLine, comma);
//		//strcpy(token, strtok(lineCopy2, ",")); // Token populated just to keep strtok in the same place in each copy
//	}
//	else
//	{
//		//strcpy(token, strtok(lineCopy2, ","));
//		strcat(usableLine, token);
//		strcat(usableLine, comma);
//	}
//	token[0] = '\0';
//	
//	// minute
//	strcpy(token, strtok(NULL, ","));
//	if (strcmp(token, "\0") == 0)
//	{
//		strcat(usableLine, invalidTime);
//		strcat(usableLine, comma);
//		//strcpy(token, strtok(lineCopy2, ","));
//	}
//	else
//	{
//		//strcpy(token, strtok(lineCopy2, ","));
//		strcat(usableLine, token);
//		strcat(usableLine, comma);
//	}
//	token[0] = '\0';
//	// calories
//	strcpy(token, strtok(NULL, ","));
//	if (strcmp(token, "\0") == 0)
//	{
//		strcat(usableLine, invalid);
//		strcat(usableLine, comma);
//		//strcpy(token, strtok(lineCopy2, ","));
//	}
//	else
//	{
//		//strcpy(token, strtok(lineCopy2, ","));
//		strcat(usableLine, token);
//		strcat(usableLine, comma);
//	}
//	token[0] = '\0';
//	// distance
//	strcpy(token, strtok(NULL, ","));
//	if (strcmp(token, "\0") == 0)
//	{
//		strcat(usableLine, invalid);
//		strcat(usableLine, comma);
//		//strcpy(token, strtok(lineCopy2, ","));
//	}
//	else
//	{
//		//strcpy(token, strtok(lineCopy2, ","));
//		strcat(usableLine, token);
//		strcat(usableLine, comma);
//	}
//	token[0] = '\0';
//	// floors
//	strcpy(token, strtok(NULL, ","));
//	if (strcmp(token, "\0") == 0)
//	{
//		strcat(usableLine, invalid);
//		strcat(usableLine, comma);
//		//strcpy(token, strtok(lineCopy2, ","));
//	}
//	else
//	{
//		//strcpy(token, strtok(lineCopy2, ","));
//		strcat(usableLine, token);
//		strcat(usableLine, comma);
//	}
//	token[0] = '\0';
//	// heartrate
//	strcpy(token, strtok(NULL, ","));
//	if (strcmp(token, "\0") == 0)
//	{
//		strcat(usableLine, invalid);
//		strcat(usableLine, comma);
//		//strcpy(token, strtok(lineCopy2, ","));
//	}
//	else
//	{
//		//strcpy(token, strtok(lineCopy2, ","));
//		strcat(usableLine, token);
//		strcat(usableLine, comma);
//	}
//	token[0] = '\0';
//	// steps
//	strcpy(token, strtok(NULL, ","));
//	if (strcmp(token, "\0") == 0)
//	{
//		strcat(usableLine, invalid);
//		strcat(usableLine, comma);
//		//strcpy(token, strtok(lineCopy2, ","));
//	}
//	else
//	{
//		//strcpy(token, strtok(lineCopy2, ","));
//		strcat(usableLine, token);
//		strcat(usableLine, comma);
//	}
//	token[0] = '\0';
//	// sleep lvl
//	strcpy(token, strtok(NULL, "\0"));
//	if (strcmp(token, "\0") == 0)
//	{
//		strcat(usableLine, invalid);
//		strcat(usableLine, comma);
//		//strcpy(token, strtok(lineCopy2, ","));
//	}
//	else
//	{
//		//strcpy(token, strtok(lineCopy2, ","));
//		strcat(usableLine, token);
//	}
//	token[0] = '\0';
//
//	return 0;
//}

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

//void insertInvalidValues(char* str, int length)
//{
//	for (int i = 0; i < length; i++)
//	{
//		if (str[i] == ' ') // empty field
//		{
//			// move all chars over by one to accommidate the - for the -1
//			for (int j = length; j > length - (i + 1); j--)
//			{
//				str[j + 2] = str[j];
//			}
//
//			str[i] = '-';
//			str[i + 1] = '1';
//		}
//	}
//}

void populateArray(FitbitData data[], int *lineCount, char line[])
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
	data[*lineCount].floors = atoi(strtok(NULL, ","));
	printf("floors: %d\n", data[*lineCount].floors);

	// heartrate
	data[*lineCount].heartRate = atoi(strtok(NULL, ","));
	printf("heartrate: %d\n", data[*lineCount].heartRate);

	// steps
	data[*lineCount].steps = atoi(strtok(NULL, ","));
	printf("steps: %d\n", data[*lineCount].steps);

	// sleep level
	data[*lineCount].sleepLevel = atoi(strtok(NULL, ","));
	printf("sleep lvl: %d\n\n", data[*lineCount].sleepLevel);





	/*strcpy(data[*lineCount].patient, strtok(line, ","));
	printf("patient: %s\n", data[*lineCount].patient);

	strcpy(data[*lineCount].minute, strtok(NULL, ","));
	printf("minute: %s\n", data[*lineCount].minute);

	data[*lineCount].calories = atof(strtok(NULL, ","));
	printf("calories: %lf\n", data[*lineCount].calories);

	data[*lineCount].distance = atof(strtok(NULL, ","));
	printf("distance: %lf\n", data[*lineCount].distance);

	data[*lineCount].floors = atoi(strtok(NULL, ","));
	printf("floors: %d\n", data[*lineCount].floors);

	data[*lineCount].heartRate = atoi(strtok(NULL, ","));
	printf("heartrate: %d\n", data[*lineCount].heartRate);

	data[*lineCount].steps = atoi(strtok(NULL, ","));
	printf("steps: %d\n", data[*lineCount].steps);

	data[*lineCount].sleepLevel = atoi(strtok(NULL, ","));
	printf("sleep lvl: %d\n\n", data[*lineCount].sleepLevel);*/ 
}