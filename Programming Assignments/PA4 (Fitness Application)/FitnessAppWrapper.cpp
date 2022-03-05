/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA4
* Date: February 16, 2022, February 20, 2022, February 23, 2022, February 24, 2022, March 1, 2022, March 4, 2022
* Description: a basic fitness application that allows the user of the application to manually edit diet and
*			   exercise plans
*/

#include "FitnessAppWrapper.h"

// constructors
FitnessAppWrapper::FitnessAppWrapper()
{
	mdietFile.open("dietPlans.txt", std::ios::in);
	mexerciseFile.open("exercisePlans.txt", std::ios::in);
}

//FitnessAppWrapper::FitnessAppWrapper(std::ifstream& newDietFile, std::ifstream& newExerciseFile)
//{
//	mdietFile = newDietFile;
//	mexerciseFile = newExerciseFile;
//}

// destructor
FitnessAppWrapper::~FitnessAppWrapper()
{
	delete [] mweekDiet;
	delete [] mweekExercise;
	mdietFile.close();
	mexerciseFile.close();
}

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

void FitnessAppWrapper::runApp()
{
	int option = 0;
	bool dietsLoaded = false, exercisesLoaded = false;
	DietPlan* targetDiet = nullptr;
	ExercisePlan* targetExercise = nullptr;
	std::ofstream dietOut, exerciseOut;

	do
	{

		displayMenu();

		option = promptForOption(1, 9);

		switch (option)
		{
		case 1: // Load weekly diet plan
			loadWeeklyPlan(mweekDiet);

			dietsLoaded = true;

			std::cout << std::endl;
			break;
		case 2: // Load weekly exercise plan
			loadWeeklyPlan(mweekExercise);

			exercisesLoaded = true;

			std::cout << std::endl;
			break;
		case 3: // Store weekly diet plan
			// closes file data member
			mdietFile.close();

			dietOut.open(DIET_INPUT, std::ios::out);

			storePlans(dietOut, mweekDiet);

			// reopens file data member
			dietOut.close();

			std::cout << std::endl << "Diet plans saved!" << std::endl << std::endl;
			break;
		case 4: // Store weekly exercise plan
			// closes file data member
			mexerciseFile.close();
			
			exerciseOut.open(EXERCISE_INPUT, std::ios::out);

			storePlans(exerciseOut, mweekExercise);

			// reopens file data member
			exerciseOut.close();

			mexerciseFile.open(EXERCISE_INPUT, std::ios::in);

			std::cout << std::endl << "Exercise plans saved!" << std::endl << std::endl;
			break;
		case 5: // Display weekly diet plan
			displayWeeklyPlan(mweekDiet);

			std::cout << std::endl;
			break;
		case 6: // Display weekly exercise plan
			displayWeeklyPlan(mweekExercise);

			std::cout << std::endl;
			break;
		case 7: // Edit daily diet plan
			promptForPlan(&targetDiet);

			targetDiet->editGoal();

			std::cout << std::endl;
			break;
		case 8: // Edit daily exercise plan
			promptForPlan(&targetExercise);

			targetExercise->editGoal();

			std::cout << std::endl;
			break;
		case 9: // Exit and write to files
			
			//// Saves Diet Plans ////
			
			if (dietsLoaded == true)
			{
				// closes file data member
				mdietFile.close();

				dietOut.open(DIET_INPUT, std::ios::out);

				storePlans(dietOut, mweekDiet);

				std::cout << std::endl << "Diet plans saved!" << std::endl;
			}

			//// Saves Exercise Plans ////
			
			if (exercisesLoaded == true)
			{
				// closes file data member
				mexerciseFile.close();

				exerciseOut.open(EXERCISE_INPUT, std::ios::out);

				storePlans(exerciseOut, mweekExercise);

				std::cout << std::endl << "Exercise plans saved!" << std::endl;
			}
			break;
		}
	} while (option != 9);

}

// file loading
void FitnessAppWrapper::loadDailyPlan(DietPlan& plan)
{
	mdietFile >> plan;
}

void FitnessAppWrapper::loadDailyPlan(ExercisePlan& plan)
{
	mexerciseFile >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan(DietPlan weekPlan[])
{
	DietPlan curPlan;
	
	for (int i = 0; i < 7; ++i)
	{
		loadDailyPlan(curPlan);
		mweekDiet[i] = curPlan;

		curPlan.clear();
	}
}

void FitnessAppWrapper::loadWeeklyPlan(ExercisePlan weekPlan[])
{
	ExercisePlan curPlan;

	for (int i = 0; i < 7; ++i)
	{
		loadDailyPlan(curPlan);
		mweekExercise[i] = curPlan;

		curPlan.clear();
	}
}

// plan displaying
void FitnessAppWrapper::displayDailyPlan(DietPlan& plan)
{
	std::cout << plan << std::endl;
}

void FitnessAppWrapper::displayDailyPlan(ExercisePlan& plan)
{
	std::cout << plan << std::endl;
}

void FitnessAppWrapper::displayWeeklyPlan(DietPlan weeklyPlan[])
{
	for (int i = 0; i < 7; ++i)
	{
		std::cout << weeklyPlan[i] << std::endl;
	}
}

void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan weeklyPlan[])
{
	for (int i = 0; i < 7; ++i)
	{
		std::cout << weeklyPlan[i] << std::endl;
	}
}

// plan editing
void FitnessAppWrapper::promptForPlan(DietPlan** targetPlan)
{
	int i = 0;
	bool valid = false;
	std::string optionDate;

	std::cout << std::endl;
	displayWeeklyPlan(mweekDiet);

	do
	{
		std::cout << std::endl << "Enter the date of the plan to be edited (mm/dd/yyyy) > ";
		std::cin >> optionDate;
		std::cout << std::endl;

		// Searches for matching plan and sets i to one after it's position in the array
		while (i < 7 && valid == false)
		{
			if (optionDate == mweekDiet[i].getDate())
			{
				valid = true;
			}
			++i;
		}
		if (valid == false)
		{
			std::cout << "Date not found! Try again." << std::endl;
			i = 0;
		}
	} while (valid == false);

	*targetPlan = &mweekDiet[i - 1];
}

void FitnessAppWrapper::promptForPlan(ExercisePlan** targetPlan)
{
	int i = 0;
	bool valid = false;
	std::string optionDate;
		
	displayWeeklyPlan(mweekExercise);
	
	do
	{
		std::cout << std::endl << "Enter the date of the plan to be edited (mm/dd/yyyy) > ";
		std::cin >> optionDate;
		std::cout << std::endl;
	
		// Searches for matching plan and sets i to one after it's position in the array
		while (i < 7 && valid == false)
		{
			if (optionDate == mweekExercise[i].getDate())
			{
				valid = true;
			}
			++i;
		}
		if (valid == false)
		{
			std::cout << "Date not found! Try again." << std::endl;
			i = 0;
		}
	} while (valid == false);

	*targetPlan = &mweekExercise[i - 1];
}

// plan storing
void FitnessAppWrapper::storePlans(std::ofstream& dietFile, DietPlan weekPlan[])
{
	for (int i = 0; i < 7; ++i)
	{
		dietFile << weekPlan[i] << std::endl;
	}
}

void FitnessAppWrapper::storePlans(std::ofstream& exerciseFile, ExercisePlan weekPlan[])
{
	for (int i = 0; i < 7; ++i)
	{
		exerciseFile << weekPlan[i] << std::endl;
	}
}

// Decided to use overloading instead
//DietPlan* FitnessAppWrapper::promptForDietPlan()
//{
//	int i = 0;
//	bool valid = false;
//	std::string optionDate;
//	
//	displayWeeklyPlan(mweekDiet);
//
//	do
//	{
//		std::cout << "Enter the date of the plan to be edited (mm/dd/yyyy) > ";
//		std::cin >> optionDate;
//		std::cout << std::endl;
//
//		// Searches for matching plan and sets i to it's position in the array
//		for (; i < 7; ++i)
//		{
//			if (optionDate == mweekDiet[i].getDate())
//			{
//				valid = true;
//			}
//		}
//		if (valid == false)
//		{
//			std::cout << "Date not found! Try again." << std::endl;
//			i = 0;
//		}
//	} while (valid == false);
//	return &mweekDiet[i];
//}
//
//ExercisePlan* FitnessAppWrapper::promptForExercisePlan()
//{
//	int i = 0;
//	bool valid = false;
//	std::string optionDate;
//
//	displayWeeklyPlan(mweekExercise);
//
//	do
//	{
//		std::cout << "Enter the date of the plan to be edited (mm/dd/yyyy) > ";
//		std::cin >> optionDate;
//		std::cout << std::endl;
//
//		// Searches for matching plan and sets i to it's position in the array
//		for (; i < 7; ++i)
//		{
//			if (optionDate == mweekExercise[i].getDate())
//			{
//				valid = true;
//			}
//		}
//		if (valid == false)
//		{
//			std::cout << "Date not found! Try again." << std::endl;
//			i = 0;
//		}
//	} while (valid == false);
//	return &mweekExercise[i];
//}

// Non member functions
int promptForOption(int lowerBound, int upperBound)
{
	int option = 0;
	do
	{
		std::cout << std::endl << "Make your selection > ";

		std::cin >> option;
	} while (option < lowerBound || option > upperBound);

	return option;
}

