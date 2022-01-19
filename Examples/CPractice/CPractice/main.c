/*
Programmer: Jesse Watson
Date: January 14, 2022
Class: Cpt_S 122 Spring 2022
Description: Example of reading and parsing a csv file
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // atoi() ascii to int

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
			strcpy(studentData[lineCount].lastname, strtok(line, ",")); // last name; strtok returns address of first char of new substring (char*)
																		// strtok starts at line(address of first character) and goes until delimiter
																		// then replaces delimiter with '\0' and returns address of first char of that string
			printf("last: %s\n", studentData[lineCount].lastname);
			strcpy(studentData[lineCount].firstname, strtok(NULL, ",")); // The NULL here has it start after the last strtok call (first char after delimiter)
																		 // remembers its place with a static variable (is retained between function calls)
			printf("first: %s\n", studentData[lineCount].firstname);
			studentData[lineCount].id = atoi(strtok(NULL, ","));
			printf("id: %d\n", studentData[lineCount].id);

			studentData[lineCount].gpa = atof(strtok(NULL, "\n"));
			printf("gpa: %lf\n", studentData[lineCount].gpa);
		}
		fclose(infile);
	}
	return 0;
}