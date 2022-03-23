// This example illustrates how to define a Stack class template.

#include "TestStack.h"

//#include <vector>

// Pre Lab Question Answers
/*
	a. I think deleting the last node of an array would be more efficient than a linked
	   list because it just traverses to the end and removes the node instead of having
	   to modify any pointers.

	b. I think deleting the first node in an array would be less efficient than a linked
	   list because you have to move all the remaining nodes back by one, while in a 
	   linked list you delete then just change the head pointer.

	c. I think deleting a node from a linked list is more efficient than deleting one from
	   an array IF all the other nodes in the array have to be moved over to fill the empty 
	   space.

	d. I think inserting a node at the end of an array is about as efficient as inserting
	   one at the end of a linked list because either way it is one operation: insert into
	   the open space at the end of the array's contents, or change the current last node's
	   next pointer to the new node.

	e. I think it is more efficient to insert a node at the front of a linked list than
	   an array because you just change the head and next pointers instead of moving all
	   the current values over in an array.

	f. I think it is more efficient to insert a node into an array than a linked list
	   because it is one operation instead of multiple to change the pointers.

	g. I think it is more efficient to access a node of an array than a linked list because
	   arrays are contiguous space while traversing a list requires jumping around between 
	   more memory.
*/

int main(void)
{
	int item1 = -89, item2 = 104;

	Stack<int> stack1;

	//	vector<int> my_vector; // vector<> is from the Standard Template Library (STL)

	TestStack<int> tester;

	tester.Test(item1, item2);

	

	return 0;
}