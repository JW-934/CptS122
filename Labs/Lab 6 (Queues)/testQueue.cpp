/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 6
* Date: February 23, 2022
* Description: Queues
*/

#include "testQueue.h"

void testEnqueue()
{
	Queue testQueue;
	
	testQueue.enqueue("Enqueue Test String");

	if (testQueue.getPTail()->getData() == "Enqueue Test String")
	{
		std::cout << "Enqueue Success: added new QueueNode to empty Queue." << std::endl;
	}
	else
	{
		std::cout << "Enqueue Failure: failed to add new QueueNode to empty Queue." << std::endl;
	}

	testQueue.enqueue("Test String 2");

	if (testQueue.getPTail()->getData() == "Test String 2")
	{
		std::cout << "Enqueue Success: added new QueueNode to non-empty Queue." << std::endl;
	}
	else
	{
		std::cout << "Enqueue Failure: failed to add new QueueNode to non-empty Queue." << std::endl;
	}
}
