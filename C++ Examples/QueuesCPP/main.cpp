#include "Queue.h"

int main(void)
{
	Queue<std::string> q;
	Queue<int> q1;

	q.enqueue("PJ1"); // string literal is a constant char*
	q.enqueue("PJ2"); // reference to a constant has to be a constant
	q.enqueue("PJ3");

	if (!q.isEmpty())
	{
		cout << "removed: " << q.dequeue() << endl;
	}

	q1.enqueue(13);
	q1.enqueue(42);
	q1.enqueue(100);

	if (!q1.isEmpty())
	{
		cout << "removed: " << q1.dequeue() << endl;
	}

	return 0;
}