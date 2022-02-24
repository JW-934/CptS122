/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA4
* Date: February 16, 2022, February 20, 2022, February 23, 2022
* Description: a basic fitness application that allows the user of the application to manually edit “diet” and
*			   “exercise” plans
*/

#pragma once

#include <iostream>
#include <fstream>
#include "DietPlan.h"
#include "ExercisePlan.h"

class FitnessAppWrapper
{
public:
	void displayMenu();
	void runApp();
private:
	DietPlan weekDiet[7];
	ExercisePlan weekExercise[7];
};

int promptForOption(int lowerBound, int upperBound);