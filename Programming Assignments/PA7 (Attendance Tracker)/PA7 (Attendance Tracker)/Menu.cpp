/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA7
* Date: March 27, 2022, April 4, 2022
* Description: This application manages attendance for a course.
*/

#include "Menu.h"

// Constructor
Menu::Menu()
{

}

// Operations
void Menu::print()
{
	std::cout << "********** Attendance Tracker **********" << std::endl;
	std::cout << "1. Import course list" << std::endl;
	std::cout << "2. Load master list" << std::endl;
	std::cout << "3. Store master list" << std::endl;
	std::cout << "4. Mark absences" << std::endl;
	//std::cout << "5. Edit absences" << std::endl; // Bonus (optional)
	std::cout << "5. Generate report" << std::endl;
	std::cout << "6. Exit" << std::endl;
	std::cout << std::endl;
}

int Menu::prompt()
{
	int option = 0;

	print();

	do
	{
		std::cout << "Make your selection > ";
		std::cin >> option;
		std::cout << std::endl;
	} while (option < 1 || option > 7);

	return option;
}