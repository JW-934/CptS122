/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Programming Assignment: PA1
* Date: January 18, 2022, January 19, 2022, January 20, 2022, January 23, 2022, January 24, 2022
* Description: This program analyzes Fitbit data
*/

#include "PA1.h"

int main(void)
{
	FILE* infile = fopen(INPUTFILE, "r");

	int lineCount = 0;
	char line[100] = "", usableLine[100] = "", lineCopy[100] = "";
	char target[10] = "";
	FitbitData data[1440] = { { '\0', '\0', 0.0, 0.0, 0, 0, 0, 0 } };

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

				puts(line);

				// Replaces spaces with -1 and fills structs in array
				populateArray(data, &lineCount, line, target);

				++lineCount;
			}
			lineCopy[0] = '\0';
		}
		fclose(infile);
	}
	
	
	
	FILE* outfile = fopen("Results.csv", "w"); // Likely move this line
	fclose(outfile);
	
	return 0;
}