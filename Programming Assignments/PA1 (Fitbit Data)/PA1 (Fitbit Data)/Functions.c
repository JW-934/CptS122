/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Programming Assignment: PA1
* Date: January 18, 2022, January 19, 2022, January 20, 2022, January 23, 2022, January 24, 2022, January 25, 2022, January 26, 2022
* Description: This program analyzes Fitbit data
*/

#include "PA1.h"

/* Name: computeAverageHR()
*  Preconditions: data[] populated with all data, lineCount accurate, empty fields made to be -1 in structs
*  Postconditions: heart rate from all structs in data[] will be averaged
*/
int computeAverageHR(FitbitData data[], int lineCount)
{
	int sum = 0;

	for (int i = 0; i < lineCount; ++i)
	{
		if (data[i].heartRate != -1)
		{
			sum += data[i].heartRate;
		}
	}
	return sum / lineCount;
}

int determineMaxSteps(FitbitData data[], int lineCount, char* maxStepEntry)
{
	int max = 0;

	for (int i = 0; i < lineCount; ++i)
	{
		if (data[i].steps > max) // More steps than current max
		{
			// Update maximum step number and the time of the maximum
			max = data[i].steps;
			maxStepEntry[0] = '\0';
			strcpy(maxStepEntry, data[i].minute);
		}
		else if (data[i].steps == max) // Same number of steps as max but later in day
		{
			// Only update the time of the maximum to latest occurance
			maxStepEntry[0] = '\0';
			strcpy(maxStepEntry, data[i].minute);
		}
	}
	return max;
}

int determineBadSleepRange(FitbitData data[], int lineCount, char* startMin, char* endMin)
{
	int maxSum = 0, currSum = 0, counting = 0;
	char start[15] = "";

	for (int i = 0; i < lineCount; ++i)
	{
		if (data[i].sleepLevel > 1)
		{
			counting = 1;
			if (data[i - 1].sleepLevel <= 1)
			{
				strcpy(start, data[i].minute);
			}
			currSum += data[i].sleepLevel;
		}
		else
		{
			if (currSum > maxSum && counting == 1)
			{
				maxSum = currSum;
				strcpy(endMin, data[i - 1].minute);
				strcpy(startMin, start);
			}
			counting = 0;
		}
	}
	return maxSum;
}

/* Name: computeTotals()
*  Preconditions: data[] populated with all data, lineCount accurate, empty fields made to be -1 in structs
*  Postconditions: data fields from all structs in data[] will be summed individually
*/
void computeTotals(FitbitData data[], int lineCount, double *totalCalories, double *totalDistance, int *totalFloors, int *totalSteps)
{
	for (int i = 0; i < lineCount; ++i)
	{
		if (data[i].calories != -1)
		{
			*totalCalories += data[i].calories;
		}
		if (data[i].distance != -1)
		{
			*totalDistance += data[i].distance;
		}
		if (data[i].floors != -1)
		{
			*totalFloors += data[i].floors;
		}
		if (data[i].steps != -1)
		{
			*totalSteps += data[i].steps;
		}
	}
}

/* Name: starsInEmptyFields()
*  Preconditions: line populated with strtok
*  Postconditions: any empty fields in the line will be have a star inserted
*/
void starsInEmptyFields(char* str, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] == ',' && str[i + 1] == ',') // back to back commas (empty field)
		{
			for (int j = 0; j < length - i; j++)
			{
				str[(length - j) + 1] = str[length - j];
			}
			str[i + 1] = '*';
		}
		if (str[i] == ',' && str[i + 1] == '\n') // comma at the end of a line (missing sleep level)
		{
			str[i + 1] = '*';
			str[i + 2] = '/n';
		}
	}
	return;
}

/* Name: populateArray()
*  Preconditions: line cleaned with starsInEmptyFields(), line verified to have target patient ID
*  Postconditions: structs in data[] will be populated with information by the minute, any empty fields set to -1
*/
void populateArray(FitbitData data[], int *lineCount, char line[], char target[])
{
	char currentToken[20] = "", invalid[] = "-1";
	
	//// patient
	//strcpy(currentToken, strtok(line, ","));
	//if (currentToken[0] != ' ')
	//{
	//	strcpy(data[*lineCount].patient, currentToken);
	//}
	//else
	//{
	//	strcpy(data[*lineCount].patient, invalid);
	//}
	//printf("patient: %s", data[*lineCount].patient);
	
	// Inserts target patient ID (if wrong data, line will be skipped in main)
	strcpy(data[*lineCount].patient, strtok(line, ","));

	// minute
	strcpy(currentToken, strtok(NULL, ","));
	if (currentToken[0] == '*')
	{
		strcpy(data[*lineCount].minute, invalid);
	}
	else
	{
		strcpy(data[*lineCount].minute, currentToken);
	}
	//printf("minute: %s", data[*lineCount].minute);

	currentToken[0] = '\0';

	// calories
	strcpy(currentToken, strtok(NULL, ","));
	if (currentToken[0] != '*')
	{
		data[*lineCount].calories = atof(currentToken);
	}
	else
	{
		data[*lineCount].calories = -1;
	}
	//printf("calories: %lf\n", data[*lineCount].calories);

	currentToken[0] = '\0';

	// distance
	strcpy(currentToken, strtok(NULL, ","));
	if (currentToken[0] != '*')
	{
		data[*lineCount].distance = atof(currentToken);
	}
	else
	{
		data[*lineCount].distance = -1;
	}
	//printf("distance: %lf\n", data[*lineCount].distance);

	currentToken[0] = '\0';

	// floors
	strcpy(currentToken, strtok(NULL, ","));
	if (currentToken[0] != '*')
	{
		data[*lineCount].floors = atoi(currentToken);
	}
	else
	{
		data[*lineCount].floors = -1;
	}
	//printf("floors: %d\n", data[*lineCount].floors);

	currentToken[0] = '\0';

	// heartrate
	strcpy(currentToken, strtok(NULL, ","));
	if (currentToken[0] != '*')
	{
		data[*lineCount].heartRate = atoi(currentToken);
	}
	else
	{
		data[*lineCount].heartRate = -1;
	}
	//printf("heart rate: %d\n", data[*lineCount].heartRate);

	currentToken[0] = '\0';

	// steps
	strcpy(currentToken, strtok(NULL, ","));
	if (currentToken[0] != '*')
	{
		data[*lineCount].steps = atoi(currentToken);
	}
	else
	{
		data[*lineCount].steps = -1;
	}
	//printf("steps: %d\n", data[*lineCount].steps);

	currentToken[0] = '\0';

	// sleep level
	strcpy(currentToken, strtok(NULL, ","));
	if (currentToken[0] != '*')
	{
		data[*lineCount].sleepLevel = atoi(currentToken);
	}
	else
	{
		data[*lineCount].sleepLevel = -1;
	}
	//printf("sleep level: %d\n", data[*lineCount].sleepLevel);

	//putchar('\n');
}

void printData(FitbitData data[], int lineCount)
{
	for (int i = 0; i < lineCount; ++i)
	{
		printf("%s,", data[i].patient);
		printf("%s,", data[i].minute);
		printf("%lf,", data[i].calories);
		printf("%lf,", data[i].distance);
		printf("%d,", data[i].floors);
		printf("%d,", data[i].heartRate);
		printf("%d,", data[i].steps);
		printf("%d\n", data[i].sleepLevel);
	}
}

void filePrintData(FILE* outfile, FitbitData data[], int lineCount)
{
	for (int i = 0; i < lineCount; ++i)
	{
		fprintf(outfile, "%s,", data[i].patient);
		fprintf(outfile, "%s,", data[i].minute);
		fprintf(outfile, "%lf,", data[i].calories);
		fprintf(outfile, "%lf,", data[i].distance);
		fprintf(outfile, "%d,", data[i].floors);
		fprintf(outfile, "%d,", data[i].heartRate);
		fprintf(outfile, "%d,", data[i].steps);
		fprintf(outfile, "%d\n", data[i].sleepLevel);
	}
}