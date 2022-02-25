#include "Queue.h"

int main(void)
{
	Queue q;

	q.enqueue("PJ1"); // string literal is a constant char*
	q.enqueue("PJ2"); // reference to a constant has to be a constant

	if (!q.isEmpty())
	{
		cout << "removed: " << q.dequeue() << endl;
	}

	return 0;
}