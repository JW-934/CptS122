/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA5
* Date: March 5, 2022, March 10, 2022
* Description: A grocery store simulation utilizing queues.
*/

#pragma once

#include "Queue.h"
#include <Windows.h>
#include <time.h>

#define TIME_PERIOD 500 // This is how many milliseconds will pass between minutes in the sim

class StoreSim
{
public:
	// Constructor
	StoreSim();

	// Destructor
	~StoreSim();
	
	// Setters


	// Getters
	int getCurTime();
	//int getSimTime();

	// Operations
	void runSim(int simTime = 0);

private:
	int mcurTime;
	//int msimTime;

	Queue normalLane;
	Queue expressLane;
};

