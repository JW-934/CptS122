/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA4
* Date: February 16, 2022, February 20, 2022, February 23, 2022, February 24, 2022, March 1, 2022
* Description: a basic fitness application that allows the user of the application to manually edit diet and
*			   exercise plans
*/

#pragma once

#include <iostream>
#include <fstream>
#include "DietPlan.h"
#include "ExercisePlan.h"

#define DIET_INPUT "dietPlans.txt"
#define EXERCISE_INPUT "exercisePlans.txt"

class FitnessAppWrapper
{
public:
	// constructors
	FitnessAppWrapper();
	/*FitnessAppWrapper(std::ifstream& dietFile, std::ifstream& exerciseFile);*/

	// destructor
	~FitnessAppWrapper();

	// file loading
	void loadDailyPlan(DietPlan& plan);
	void loadDailyPlan(ExercisePlan& plan);

	void loadWeeklyPlan(DietPlan weekPlan[]);
	void loadWeeklyPlan(ExercisePlan weekPlan[]);

	// plan displaying
	void displayDailyPlan(DietPlan& plan);
	void displayDailyPlan(ExercisePlan& plan);

	void displayWeeklyPlan(DietPlan weeklyPlan[]);
	void displayWeeklyPlan(ExercisePlan weeklyPlan[]);

	// plan editing
	void promptForPlan(DietPlan* targetPlan);
	void promptForPlan(ExercisePlan* targetPlan);
	//DietPlan* promptForDietPlan();
	//ExercisePlan* promptForExercisePlan();

	// etc
	void displayMenu();
	void runApp();
private:
	DietPlan mweekDiet[7];
	ExercisePlan mweekExercise[7];
	std::ifstream mdietFile;
	std::ifstream mexerciseFile;
};

int promptForOption(int lowerBound, int upperBound);

