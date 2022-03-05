/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA5
* Date: March 5, 2022
* Description: A grocery store simulation utilizing queues.
*/

#include <iostream>
#include "Queue.h"
#include "testQueue.h"

int main()
{
	testEnqueue();
	testIsEmpty();
	testDequeue();
	testPrintQueueRec();

	return 0;
}