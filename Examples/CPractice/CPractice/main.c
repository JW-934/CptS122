/*
Programmer: Jesse Watson
Date: January 14, 2022
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

typedef struct student // name on this line optional
{
	char lastname[25];
	char firstname[25];
	int id;
	double gpa;
}Student;

int main(void)
{
	FILE* infile = fopen("data.csv", "r");
	char line[100] = ""; // empty string line[0] = '\0'; with one array fgets will overwrite each time, array of structs better
	Student studentData[100] = { {"", "", 0, 0.0} };
	int lineCount = 0;

	if (infile != NULL) // NULL pointer returned if fails to open
	{
		// File opened successfully
		// 1. read in header line
		fgets(line, 100, infile); // reads in one less than max count to leave room for '\0'
		puts(line);

		// can't read anymore lines of data; fgets() returns NULL pointer
		while (fgets(line, 100, infile) != NULL) // !feof(infile) fgets returns max count unless there is no data left
		{
			puts(line);
			// strtok () to parse a line; .csv file
		}
		fclose(infile);
	}
	return 0;
}