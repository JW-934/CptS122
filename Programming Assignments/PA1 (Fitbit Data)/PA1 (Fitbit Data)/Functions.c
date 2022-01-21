/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Programming Assignment: PA1
* Date: January 18, 2022, January 19, 2022, January 20, 2022
* Description: This program analyzes Fitbit data
*/

#include "PA1.h"

void populateEmptyFields(char* line)
{
	char* line[100] = "";
	
	fgets(line, 100, infile); // reads in one less than max count to leave room for '\0'
	puts(line);

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