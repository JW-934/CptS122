/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA5
* Date: March 5, 2022, March 10, 2022
* Description: A grocery store simulation utilizing queues.
*/

#include "StoreSim.h"

// Constructor
StoreSim::StoreSim()
{
	//msimTime = 0;
	mcurTime = 0;
}

// Destructor
StoreSim::~StoreSim()
{

}

// Setters

// Getters
int StoreSim::getCurTime()
{
	return mcurTime;
}
//int StoreSim::getSimTime()
//{
//	return msimTime;
//}

// Operations
void StoreSim::runSim(int simTime)
{
	int normArriveTime = rand() % (8 + 1 - 3) + 3;
	int expArriveTime = rand() % (5 + 1 - 1) + 1;
	int normArriveIndex = normArriveTime, expArriveIndex = expArriveTime, normLeaveIndex = 0, expLeaveIndex = 0;;
	int currCustNum = 1, currNormTimeSum = 0, currExpTimeSum = 0, newServiceTime;
	Data currCust;

	do
	{
		std::cout << "Minute " << mcurTime << ":" << std::endl;

		if (normArriveIndex == 0) // Time for a normal customer to arrive
		{
			newServiceTime = rand() % (10 + 1 - 3) + 3; // Service time of 3-10 mins

			normalLane.enqueue(currCustNum, newServiceTime, currNormTimeSum + newServiceTime);

			std::cout << "Customer " << currCustNum << " has entered the normal lane." << std::endl;

			currNormTimeSum += newServiceTime;
			++currCustNum;
			normArriveIndex = normArriveTime;
		}

		if (expArriveIndex == 0) // Time for an express customer to arrive
		{
			newServiceTime = rand() % (6 + 1 - 2) + 2; // Service time of 2-6 mins

			expressLane.enqueue(currCustNum, newServiceTime, currExpTimeSum + newServiceTime);

			std::cout << "Customer " << currCustNum << " has entered the express lane." << std::endl;

			currExpTimeSum += newServiceTime;
			++currCustNum;

			expArriveIndex = expArriveTime;
		}

		if (normalLane.getPHead() != nullptr)
		{
			if (normLeaveIndex == normalLane.getPHead()->getData().getServTime()) // Time for normal customer to leave
			{
				std::cout << "Customer " << normalLane.getPHead()->getData().getNumber() << " has left the normal lane." << std::endl;

				currCust = normalLane.dequeue();

				if (normalLane.getPHead() != nullptr)
				{
					normalLane.getPHead()->getData().setTotalTime(normalLane.getPHead()->getData().getTotalTime() - currCust.getServTime());
				}
				normLeaveIndex = 0;
			}
		}

		if (expressLane.getPHead() != nullptr)
		{
			if (expLeaveIndex == expressLane.getPHead()->getData().getServTime()) // Time for express customer to leave
			{
				std::cout << "Customer " << expressLane.getPHead()->getData().getNumber() << " has left the express lane." << std::endl;

				currCust = expressLane.dequeue();

				if (expressLane.getPHead() != nullptr)
				{
					expressLane.getPHead()->getData().setTotalTime(expressLane.getPHead()->getData().getTotalTime() - currCust.getServTime());
				}
				expLeaveIndex = 0;
			}
		}

		if (mcurTime % 10 == 0)	// Time to print queues (multiple of ten mins)
		{
			std::cout << "Normal Lane: " << std::endl;
			printQueueRecursive(normalLane.getPHead());

			std::cout << "Express Lane: " << std::endl;
			printQueueRecursive(expressLane.getPHead());
		}

		--normArriveIndex;
		--expArriveIndex;
		++normLeaveIndex;
		++expLeaveIndex;
		++mcurTime;
		std::cout << std::endl;

		Sleep(TIME_PERIOD);
	} while (mcurTime <= simTime);
}