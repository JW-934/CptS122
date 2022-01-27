/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Programming Assignment: PA1
* Date: January 18, 2022, January 19, 2022, January 20, 2022, January 23, 2022, January 24, 2022, January 25, 2022, January 26, 2022
* Description: This program analyzes Fitbit data
*/

#include "PA1.h"

int main(void)
{
	FILE* infile = fopen(INPUTFILE, "r");

	int lineCount = 0, totalFloors = 0, totalSteps = 0, averageHR = 0, maxSteps, maxBadSleep;
	char line[100] = "", usableLine[100] = "", lineCopy[100] = "", target[10] = "", maxStepEntry[15] = "", sleepStart[15] = "", sleepEnd[15] = "";
	
	double totalCalories = 0, totalDistance = 0;
	
	FitbitData data[1445] = { { '\0', '\0', 0.0, 0.0, 0, 0, 0, 0 } }; // Warning message can be prevented if array size increased slightly

	if (infile != NULL) // Input file successfully opened
	{
		// Gets and saves target user ID
		fscanf(infile, "Target: ,"); // Reads in "Target: ," so next strtok just grabs the target ID
		
		fgets(line, 100, infile);
		strcpy(target, strtok(line, ","));

		// Skips over header line
		fgets(line, 100, infile);

		// Populates fields of each struct in data[] after error correction
		while (fgets(line, 100, infile) != NULL)
		{
			// Checks if patient ID in line matches the target ID
			strcpy(lineCopy, line);
			if (strcmp(strtok(lineCopy, ","), target) == 0)
			{
				//puts(line);

				// Fills empty fields with spaces
				starsInEmptyFields(line, strlen(line));

				//puts(line);

				// Replaces spaces with -1 and fills structs in array
				populateArray(data, &lineCount, line, target);

				++lineCount;
			}
			lineCopy[0] = '\0';
		}
		fclose(infile);

		// Calculates all totals
		computeTotals(data, lineCount, &totalCalories, &totalDistance, &totalFloors, &totalSteps);
		/*printf("total calories: %lf\n", totalCalories);
		printf("total distance: %lf\n", totalDistance);
		printf("total floors: %d\n", totalFloors);
		printf("total steps: %d\n", totalSteps);*/

		// Calculates average heart rate
		averageHR = computeAverageHR(data, lineCount);
		//printf("average heartrate: %d\n", averageHR);

		// Finds maximum steps and when it happened
		maxSteps = determineMaxSteps(data, lineCount, maxStepEntry);
		//printf("max steps in one minute: %d at %s\n", maxSteps, maxStepEntry);

		maxBadSleep = determineBadSleepRange(data, lineCount, sleepStart, sleepEnd);

		/*printf("bad sleep range start: ");
		puts(sleepStart);
		printf("bad sleep range end: ");
		puts(sleepEnd);*/

		FILE* outfile = fopen("Results.csv", "w");

		// Print header to screen and to results file
		printf("Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
		fprintf(outfile, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");

		printf("%lf, %lf, %d, %d, %d, %d at %s, start: %s, end: %s\n", totalCalories, totalDistance, totalFloors, totalSteps, averageHR, maxSteps, maxStepEntry, sleepStart, sleepEnd);
		fprintf(outfile, "%lf, %lf, %d, %d, %d, %d at %s, start: %s, end: %s\n", totalCalories, totalDistance, totalFloors, totalSteps, averageHR, maxSteps, maxStepEntry, sleepStart, sleepEnd);
		
		// Print cleaned data to screen and output file
		printData(data, lineCount);
		filePrintData(outfile, data, lineCount);

		fclose(outfile);
	}
	return 0;
}