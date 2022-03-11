/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA5
* Date: March 5, 2022, March 10, 2022
* Description: A grocery store simulation utilizing queues.
*/

#include <iostream>
#include <time.h>
#include "Queue.h"
#include "tests.h"
#include "StoreSim.h"

int main()
{
	int overallTime = 0;
	srand((unsigned)time(NULL));

	// Test cases NOTE: I have combined some of the tests //////////////////////////////////////////////////
	
	//testEnqueue();

	//testIsEmpty();

	//testDequeue();

	//testPrintQueueRec();

	testSim(25);
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Store Simulation ////////////////////////////////////////////////////////////////////////////////////
	
	//int minutes = -1;
	//StoreSim sim1;

	//// Prompts for number of minutes
	//do
	//{
	//	std::cout << "Enter the number of minutes the simulation will run: ";
	//	std::cin >> minutes;
	//	std::cout << std::endl;
	//} while (minutes < 0);

	//sim1.runSim(minutes);

	///////////////////////////////////////////////////////////////////////////////////////////////////////

	return 0;
}