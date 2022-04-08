/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA7
* Date: March 27, 2022, April 4, 2022, April 7, 2022
* Description: This application manages attendance for a course.
*/

#include "Menu.h"
#include "List.h"

int main()
{
	int option = 0, reportType = 0;
	Menu menu;
	fstream infile, masterFile;
	string current, discard;

	// New record variables
	int newRecNum, newID, newUnits;
	string newName, newEmail, newMajor, newLevel, newFirstN, newLastN;
	Data* pnewData;

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
				
				masterFile << current;
				
				if (infile.peek())///////////////////////////////////////////////////Current Problem//////////////////////////////////////
				{
					masterFile << " ";
				}
				else
				{
					
				}

				current.clear();

				//getline(infile, current, ',');
				//newRecNum = atoi(current.c_str());

				//getline(infile, current, ',');
				//newID = atoi(current.c_str());

				//getline(infile, newLastN, ',');
				//getline(infile, newFirstN, ',');
				///*infile >> newLastN;
				//infile >> newFirstN;*/
				//newName += newLastN + ", ";
				//newName += newFirstN;
				////current.clear();

				////infile >> newEmail;
				//getline(infile, newEmail, ',');

				//getline(infile, current, ',');
				//newUnits = atoi(current.c_str());
				////current.clear();

				///*infile >> newMajor;
				//infile >> newLevel*/;
				//getline(infile, newMajor, ',');
				//getline(infile, newLevel, ',');

				//masterFile << newRecNum << " " << newID << " " << newName << " " << newEmail << " " << newUnits << " "
				//	<< newMajor << " " << newLevel;

				//newName.clear();
				//newFirstN.clear();
				//newLastN.clear();
				//newEmail.clear();
				//newMajor.clear();
				//newLevel.clear();//
			}

			infile.close();
			masterFile.close();

			break;
		case 2: // Load master list
			masterFile.open("master.txt", std::ios::in);

			//masterFile >> discard; // discards blank line
			
			while (!masterFile.eof())
			{
				/*getline(masterFile, current, ',');
				newRecNum = atoi(current.c_str());
				current.clear();

				getline(masterFile, current, ',');
				newID = atoi(current.c_str());
				current.clear();

				getline(masterFile, newName, ',');

				getline(masterFile, newEmail, ',');

				getline(masterFile, current, ',');
				newUnits = atoi(current.c_str());
				current.clear();

				getline(masterFile, newMajor, ',');

				getline(masterFile, newLevel, ',');*/

				masterFile >> current;
				newRecNum = atoi(current.c_str());

				masterFile >> current;
				newID = atoi(current.c_str());

				masterFile >> newLastN;
				masterFile >> newFirstN;
				newName += newLastN + ", ";
				newName += newFirstN;
				//current.clear();

				masterFile >> newEmail;

				masterFile >> current;
				newUnits = atoi(current.c_str());
				//current.clear();

				masterFile >> newMajor;
				masterFile >> newLevel;


				pnewData = new Data(newRecNum, newID, newName, newEmail, newUnits, newMajor, newLevel);

				masterList.insertFront(*pnewData);

				newName.clear();
				newFirstN.clear();
				newLastN.clear();
				newEmail.clear();
				newMajor.clear();
				newLevel.clear();
			}

			masterFile.close();

			// Printing list for testing
			masterList.printListRec();
















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