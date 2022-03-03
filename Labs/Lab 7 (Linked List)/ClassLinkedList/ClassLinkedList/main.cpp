#include "ListApp.h"

int main(void)
{
	// Start with debugging this project! "Step Into" each statement to answer the questions!
	// Question 1: what function is called in the statement below?		// Ans: Line 7 calls the defined constructor using the default parameter (nothing passed in)
	ListNode n1;
	// Question 2: what function is called in the statement below?		// Ans: Line 8 calls the defined constructor but with a nondefault parameter; deep copy
	ListNode n2(42); // shallow or deep copy?
	// Question 3: what function is called in the statement below?		// Ans: Line 11 calls the copy constructor which performs a shallow copy
	ListNode n3(n2); // shallow or deep copy?
	// Question 4: what function is called in the statement below?		// Ans: line 13 calls the default constructor then the implicit copy constructor which performs a shallow copy
	ListNode n4 = n3; // shallow or deep copy? 

	ListNode n5;
	// Question 5: what function/operator is called in the statement below?		// Ans: Line 17 calls the implicit copy constructor. We did not explicitly define this operator.
	n5 = n4; // did we explicitly implement this function/operator? 

	// Question 6: what function is called in the statement below?		// Ans: Line 20 calls the defined default constructor for a list
	List l1;
	// make sure that you finish implementing the copy constructor for the List object before you try to 
	// execute the next statement!
	// Question 7: what function is called in the statement below? What would happen if we did not		// Ans: Line 25 invokes the defined copy constructor to perform a deep copy.
	//             explicitly implement the function? Would the compiler generated one be good enough?	// I don't think the implicit one would work well because it would only assign
	 List l2 = l1; // shallow or deep copy?																// pointers instead of copying over the actual values (shallow copy).
	// Question 8: what would happen if a shallow copy constructor is used, instead of a deep copy constructor, 
	//             when the destructor for each list object is implicily invoked? l2 and l1 would have the same				// Ans: The destructor would deallocate memory that other nodes could be using
	//             address stored in the head pointer, and thus, one of the lists would be freed and when the other went	// because it is deleting through a pointer. When those other nodes are ready
	//             out of scope, the destructor would try to access already freed memory (a dangling pointer situation)!	// to be deconstructed the deconstructor will try to delete already deleted memory.


	List l3;
	// make sure that you finish implementing the overloaded assignment for the List object before you try to 
	// execute the next statement!
	// Question 9: what function is called in the statement below? What would happen if we did not			// Ans: Line 37 invokes the defined overloaded assignment operator.
	//             explicitly implement the function? Would the compiler generated one be good enough?		// This results in a deep copy, the compiler generated one would
	l3 = l2; // shallow or deep copy?																		// make a shallow copy, which could result in a destructor trying
	// Question 10: what would happen if a shallow copy assignment is used, instead of a deep copy assignment, // to deallocate memory that is already deallocated
	//              when the destructor for each list object is implicily invoked? l3 and l2 would have the same
	//              address stored in the head pointer, and thus, one of the lists would be freed and when the other went
	//              out of scope, the destructor would try to access already freed memory (a dangling pointer situation)!

	// Question 11: how does the List destructor free up the nodes? You will need to visit "List.cpp" to answer this question!

	ListApp app;

	app.runApp();

	return 0;
}