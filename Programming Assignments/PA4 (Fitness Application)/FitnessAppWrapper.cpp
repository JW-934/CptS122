/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA4
* Date: February 16, 2022, February 20, 2022, February 23, 2022
* Description: a basic fitness application that allows the user of the application to manually edit “diet” and
*			   “exercise” plans
*/

#include "FitnessAppWrapper.h"

void FitnessAppWrapper::displayMenu()
{
	std::cout << "******************** Fitness App Main Menu ********************" << std::endl;

	std::cout << "1. Load weekly diet plan from file." << std::endl;
	std::cout << "2. Load weekly exercise plan from file." << std::endl;
	std::cout << "3. Store weekly diet plan to file." << std::endl;
	std::cout << "4. Store weekly exercise plan to file." << std::endl;
	std::cout << "5. Display weekly diet plan to screen." << std::endl;
	std::cout << "6. Display weekly exercise plan to screen." << std::endl;
	std::cout << "7. Edit daily diet plan." << std::endl;
	std::cout << "8. Edit daily exercise plan." << std::endl;
	std::cout << "9. Exit." << std::endl;
}

int promptForOption(int lowerBound, int upperBound)
{
	int option = 0;
	do
	{
		std::cout << "Make your selection > ";

		std::cin >> option;
	} while (option < lowerBound || option > upperBound);

	return option;
}

void FitnessAppWrapper::runApp()
{
	int option = 0;

	do
	{
		option = promptForOption(1, 9);

		switch (option)
		{
		case 1: // Load weekly diet plan
			break;
		case 2: // Load weekly exercise plan
			break;
		case 3: // Store weekly diet plan
			break;
		case 4: // Store weekly exercise plan
			break;
		case 5: // Display weekly diet plan
			break;
		case 6: // Display weekly exercise plan
			break;
		case 7: // Edit daily diet plan
			break;
		case 8: // Edit daily exercise plan
			break;
		case 9: // Exit and write to files
			break;
		}
	} while (option != 9);

}