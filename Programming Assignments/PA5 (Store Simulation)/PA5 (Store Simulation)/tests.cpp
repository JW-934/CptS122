/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA5
* Date: March 5, 2022, March 10, 2022
* Description: A grocery store simulation utilizing queues.
*/

#include "tests.h"

void testEnqueue()
{
	Queue testQueue;
	
	std::cout << "******************** enqueue() Test ********************" << std::endl;

	testQueue.enqueue(1, 10, 15);
	std::cout << "TEST:" << std::endl;

	if (testQueue.getPTail()->getData().getNumber() == 1)
	{
		std::cout << "enqueue() Success: added new QueueNode to empty Queue." << std::endl;
	}
	else
	{
		std::cout << "enqueue() Failure: failed to add new QueueNode to empty Queue." << std::endl;
	}

	putchar('\n');
	testQueue.enqueue(2, 20, 25);

	std::cout << "TEST:" << std::endl;
	if (testQueue.getPTail()->getData().getNumber() == 2)
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
	std::cout << "TEST:" << std::endl;
	if (testQueue.isEmpty())
	{
		std::cout << "isEmpty() Success: determined that empty Queue is empty." << std::endl;
	}
	else
	{
		std::cout << "isEmpty() Failure: failed to determine that empty Queue is empty." << std::endl;
	}

	putchar('\n');
	// Prepares non-empty test queue
	testQueue.enqueue(1, 10, 15);

	std::cout << "PREPARATION:" << std::endl;

	if (testQueue.getPTail()->getData().getNumber() == 1)
	{
		std::cout << "enqueue() Success: added new QueueNode to isEmpty() test Queue." << std::endl;
	}
	else
	{
		std::cout << "enqueue() Failure: failed to add new QueueNode to isEmpty() test Queue." << std::endl;
	}

	putchar('\n');
	// Checks if non-empty queue is empty
	std::cout << "TEST:" << std::endl;
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
	Data data;

	std::cout << "******************** dequeue() Test ********************" << std::endl;

	// Prepares 1 node test queue

	std::cout << "PREPARATION:" << std::endl;

	testQueue.enqueue(1, 10, 15);

	if (testQueue.getPTail()->getData().getNumber() == 1)
	{
		std::cout << "enqueue() Success: added new QueueNode to dequeue() test Queue." << std::endl;
	}
	else
	{
		std::cout << "enqueue() Failure: failed to add new QueueNode to dequeue() test Queue." << std::endl;
	}

	data = testQueue.dequeue();
	 
	putchar('\n');
	// Checks if pTail is null
	std::cout << "TEST:" << std::endl;
	if (testQueue.getPTail() == nullptr)
	{
		std::cout << "dequeue() Success: removed QueueNode from test Queue containing one QueueNode." << std::endl;
	}
	else
	{
		std::cout << "dequeue() Failure: failed to remove QueueNode from test Queue containing one QueueNode." << std::endl;
	}

	if (data.getNumber() == 1)
	{
		std::cout << "dequeue() Success: returned data from removed QueueNode." << std::endl;
	}
	else
	{
		std::cout << "dequeue() Failure: failed to return data from removed QueueNode." << std::endl;
	}
	putchar('\n');

	data.clear();

	// Prepares 2 node test queue

	std::cout << "PREPARATION:" << std::endl;

	testQueue.enqueue(2, 20, 25);

	if (testQueue.getPTail()->getData().getNumber() == 2)
	{
		std::cout << "enqueue() Success: added new QueueNode to dequeue() test Queue." << std::endl;
	}
	else
	{
		std::cout << "enqueue() Failure: failed to add new QueueNode to dequeue() test Queue." << std::endl;
	}

	testQueue.enqueue(3, 30, 25);

	if (testQueue.getPTail()->getData().getNumber() == 3)
	{
		std::cout << "enqueue() Success: added new QueueNode to dequeue() test Queue." << std::endl;
	}
	else
	{
		std::cout << "enqueue() Failure: failed to add new QueueNode to dequeue() test Queue." << std::endl;
	}

	data = testQueue.dequeue();

	putchar('\n');
	// Checks if node get removed

	std::cout << "TEST:" << std::endl;
	if (testQueue.getPHead()->getData().getNumber() == 3)
	{
		std::cout << "dequeue() Success: removed QueueNode from test Queue containing two QueueNodes." << std::endl;
	}
	else
	{
		std::cout << "dequeue() Failure: failed to remove QueueNode from test Queue containing two QueueNodes." << std::endl;
	}


	if (data.getNumber() == 2)
	{
		std::cout << "dequeue() Success: returned data from removed QueueNode." << std::endl;
	}
	else
	{
		std::cout << "dequeue() Failure: failed to return data from removed QueueNode." << std::endl;
	}

	putchar('\n');
}

void testPrintQueueRec()
{
	Queue testQueue;
	std::string data;

	std::cout << "******************** printQueueRecursive() Test ********************" << std::endl;

	// Prepares 1 node test queue

	std::cout << "PREPARATION:" << std::endl;

	testQueue.enqueue(1, 10, 15);

	if (testQueue.getPTail()->getData().getNumber() == 1)
	{
		std::cout << "enqueue() Success: added new QueueNode to printQueueRecursive() test Queue." << std::endl;
	}
	else
	{
		std::cout << "enqueue() Failure: failed to add new QueueNode to printQueueRecursive() test Queue." << std::endl;
	}
	putchar('\n');

	std::cout << "TEST:" << std::endl;

	std::cout << "printQueueRecursive() Output:" << std::endl << std::endl;
	printQueueRecursive(testQueue.getPHead());

	// Adds 2 more nodes to test queue

	std::cout << "PREPARATION:" << std::endl;

	testQueue.enqueue(2, 20, 25);

	if (testQueue.getPTail()->getData().getNumber() == 2)
	{
		std::cout << "enqueue() Success: added new QueueNode to printQueueRecursive() test Queue." << std::endl;
	}
	else
	{
		std::cout << "enqueue() Failure: failed to add new QueueNode to printQueueRecursive() test Queue." << std::endl;
	}

	testQueue.enqueue(3, 30, 35);

	if (testQueue.getPTail()->getData().getNumber() == 3)
	{
		std::cout << "enqueue() Success: added new QueueNode to printQueueRecursive() test Queue." << std::endl;
	}
	else
	{
		std::cout << "enqueue() Failure: failed to add new QueueNode to printQueueRecursive() test Queue." << std::endl;
	}
	putchar('\n');
	std::cout << "TEST:" << std::endl;

	std::cout << "printQueueRecursive() Output:" << std::endl << std::endl;
	printQueueRecursive(testQueue.getPHead());
	putchar('\n');
}

void testSim(int minutes)
{
	StoreSim sim;

	sim.runSim(minutes);
}