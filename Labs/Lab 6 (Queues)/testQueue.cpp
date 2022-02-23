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
	
	std::cout << "******************** enqueue() Test ********************" << std::endl;

	testQueue.enqueue("Enqueue Test String");

	if (testQueue.getPTail()->getData() == "Enqueue Test String")
	{
		std::cout << "enqueue() Success: added new QueueNode to empty Queue." << std::endl;
	}
	else
	{
		std::cout << "enqueue() Failure: failed to add new QueueNode to empty Queue." << std::endl;
	}

	testQueue.enqueue("Test String 2");

	if (testQueue.getPTail()->getData() == "Test String 2")
	{
		std::cout << "enqueue() Success: added new QueueNode to non-empty Queue." << std::endl;
	}
	else
	{
		std::cout << "enqueue() Failure: failed to add new QueueNode to non-empty Queue." << std::endl;
	}
	putchar('\n');
}

void testIsEmpty()
{
	Queue testQueue;

	std::cout << "******************** isEmpty() Test ********************" << std::endl;

	// Checks if empty queue is empty
	if (testQueue.isEmpty())
	{
		std::cout << "isEmpty() Success: determined that empty Queue is empty." << std::endl;
	}
	else
	{
		std::cout << "isEmpty() Failure: failed to determine that empty Queue is empty." << std::endl;
	}

	// Prepares non-empty test queue
	testQueue.enqueue("Enqueue Test String");

	if (testQueue.getPTail()->getData() == "Enqueue Test String")
	{
		std::cout << "enqueue() Success: added new QueueNode to isEmpty() test Queue." << std::endl;
	}
	else
	{
		std::cout << "enqueue() Failure: failed to add new QueueNode to isEmpty() test Queue." << std::endl;
	}

	// Checks is non-empty queue is empty
	if (!testQueue.isEmpty())
	{
		std::cout << "isEmpty() Success: determined that non-empty Queue is not empty." << std::endl;
	}
	else
	{
		std::cout << "isEmpty() Failure: failed to determine that non-Queue is not empty." << std::endl;
	}
	putchar('\n');
}

void testDequeue()
{
	Queue testQueue;
	std::string data;

	std::cout << "******************** dequeue() Test ********************" << std::endl;

	// Prepares 1 node test queue
	testQueue.enqueue("Dequeue Test String");

	if (testQueue.getPTail()->getData() == "Dequeue Test String")
	{
		std::cout << "enqueue() Success: added new QueueNode to dequeue() test Queue." << std::endl;
	}
	else
	{
		std::cout << "enqueue() Failure: failed to add new QueueNode to dequeue() test Queue." << std::endl;
	}

	data = testQueue.dequeue();
	 
	// Checks if pTail is null
	if (testQueue.getPTail() == nullptr)
	{
		std::cout << "dequeue() Success: removed QueueNode from test Queue containing one QueueNode." << std::endl;
	}
	else
	{
		std::cout << "dequeue() Failure: failed to remove QueueNode from test Queue containing one QueueNode." << std::endl;
	}

	if (data == "Dequeue Test String")
	{
		std::cout << "dequeue() Success: returned data from removed QueueNode." << std::endl;
	}
	else
	{
		std::cout << "dequeue() Failure: failed to return data from removed QueueNode." << std::endl;
	}

	data.clear();

	// Prepares 2 node test queue
	testQueue.enqueue("Dequeue Test String 2");

	if (testQueue.getPTail()->getData() == "Dequeue Test String 2")
	{
		std::cout << "enqueue() Success: added new QueueNode to dequeue() test Queue." << std::endl;
	}
	else
	{
		std::cout << "enqueue() Failure: failed to add new QueueNode to dequeue() test Queue." << std::endl;
	}

	testQueue.enqueue("Dequeue Test String 3");

	if (testQueue.getPTail()->getData() == "Dequeue Test String 3")
	{
		std::cout << "enqueue() Success: added new QueueNode to dequeue() test Queue." << std::endl;
	}
	else
	{
		std::cout << "enqueue() Failure: failed to add new QueueNode to dequeue() test Queue." << std::endl;
	}

	data = testQueue.dequeue();

	// Checks if node get removed
	if (testQueue.getPHead()->getData() == "Dequeue Test String 3")
	{
		std::cout << "dequeue() Success: removed QueueNode from test Queue containing two QueueNodes." << std::endl;
	}
	else
	{
		std::cout << "dequeue() Failure: failed to remove QueueNode from test Queue containing two QueueNodes." << std::endl;
	}

	if (data == "Dequeue Test String 2")
	{
		std::cout << "dequeue() Success: returned data from removed QueueNode." << std::endl;
	}
	else
	{
		std::cout << "dequeue() Failure: failed to return data from removed QueueNode." << std::endl;
	}

	putchar('\n');
}