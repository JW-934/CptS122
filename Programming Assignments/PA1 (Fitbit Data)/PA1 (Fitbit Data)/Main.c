/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Programming Assignment: PA1
* Date: January 18, 2022, January 19, 2022, January 20, 2022
* Description: This program analyzes Fitbit data
*/

#include "PA1.h"

int main(void)
{
	FILE* infile = fopen(INPUTFILE, "r");

	int lineCount = 0;
	char line[100] = "";
	char target[10] = "";
	FitbitData data[1440] = { { '\0', '\0', 0.0, 0.0, 0, 0, 0, 0 } };

	if (infile != NULL) // Input file successfully opened
	{
		// Gets and saves target user ID
		fscanf(infile, "Target: ,"); // Reads in "Target: ," so next strtok just grabs the target ID
		
		fgets(line, 100, infile);
		strcpy(target, strtok(line, ","));
		
		printf("target: %s\n\n", target);

		// Skips over header line
		fgets(line, 100, infile);
		//puts(line);

		// Populates fields of each struct in data[]
		while (fgets(line, 100, infile) != NULL)
		{
			puts(line);
			strcpy(data[lineCount].patient, strtok(line, ","));
			printf("patient: %s\n", data[lineCount].patient);
			
			strcpy(data[lineCount].minute, strtok(NULL, ","));
			printf("minute: %s\n", data[lineCount].minute);

			data[lineCount].calories = atof(strtok(NULL, ","));
			printf("calories: %lf\n", data[lineCount].calories);

			data[lineCount].distance = atof(strtok(NULL, ","));
			printf("distance: %lf\n", data[lineCount].distance);

			data[lineCount].floors = atoi(strtok(NULL, ","));
			printf("floors: %d\n", data[lineCount].floors);

			data[lineCount].heartRate = atoi(strtok(NULL, ","));
			printf("heartrate: %d\n", data[lineCount].heartRate);

			data[lineCount].steps = atoi(strtok(NULL, ","));
			printf("steps: %d\n", data[lineCount].steps);

			data[lineCount].sleepLevel = atoi(strtok(NULL, ","));
			printf("sleep lvl: %d\n\n", data[lineCount].sleepLevel);

			++lineCount;
		}
		fclose(infile);
	}
	FILE* outfile = fopen("Results.csv", "w"); // Likely move this line
	fclose(outfile);
	
	return 0;
}