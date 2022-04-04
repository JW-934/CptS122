/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA7
* Date: March 27, 2022, April 4, 2022
* Description: This application manages attendance for a course.
*/

#include "Menu.h"
#include "List.h"
#include "Data.h"

int main()
{
	int option = 0, reportType = 0;
	Menu menu;
	fstream infile, masterFile;
	string current, discard;

	// New record variables
	int newRecNum, newID, newUnits;
	string newName, newEmail, newMajor, newLevel;

	List<Data> masterList;

	do
	{
		option = menu.prompt();

		switch (option)
		{
		case 1: // Import course list
			infile.open("classList.csv", std::ios::in);
			masterFile.open("master.txt", std::ios::out);

			infile >> discard; // discards csv header
			while (!infile.eof())
			{
				getline(infile, current, ',');
				
				masterFile << current << " ";
			}

			infile.close();
			masterFile.close();

			break;
		case 2: // Load master list
			masterFile.open("master.txt", std::ios::in);

			masterFile >> discard; // discards blank line
			
			while (!masterFile.eof())
			{
				getline(masterFile, current, ',');
				newRecNum = atoi(current.c_str());

				getline(masterFile, current, ',');
				newID = atoi(current.c_str());

				getline(masterFile, newName, ',');

				getline(masterFile, newEmail, ',');

				getline(masterFile, current, ',');
				newUnits = atoi(current.c_str());

				getline(masterFile, newMajor, ',');

				getline(masterFile, newLevel, ',');

				masterList.insertFront(new Data(newRecNum, newID, newName, newEmail, newUnits, newMajor, newLevel));
			}

			masterFile.close();

			// Printing list for testing
			cout << masterList.getPhead()->getData()
















			break;
		case 3: // Store master list

			break;
		case 4: // Mark absences

			break;
		case 5: // Generate report
			do
			{
				cout << "Report 1: All Students" << endl << "Report 2: Students Past Threshold" << endl;

				std::cout << "Make your selection > ";
				std::cin >> reportType;
				std::cout << std::endl;
			} while (reportType < 1 || reportType > 2);

			if (reportType == 1) // All students
			{

			}
			else // Past threshold
			{

			}

			break;
		case 6: // Exit

			break;
		}
	} while (option != 6);
	return 0;
}