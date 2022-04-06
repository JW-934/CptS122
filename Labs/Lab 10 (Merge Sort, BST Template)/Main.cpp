/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 10
* Date: April 6, 2022
* Description: Implementation of merge sort and a BST deleteNode() template
*/

#include "MergeSort.h"
#include "BST.h"

int main()
{
	// Merge Sort /////////////////////////////////////////////////////////
	// Since merge sort is index based, the function will run all the way through
	// the array even if it starts sorted. Therefore the worst, best, and average
	// cases are the same.

	int arr[15] = {3, 5, 2, 6, 4, 8, 4, 9, 0, 1};

	std::cout << "********** mergeSort() Test **********" << std::endl;

	// Prints original array
	std::cout << "Original Array: " << " ";
	printArray(arr, 10);
	std::cout << std::endl;

	mergeSort(arr, 0, 9);

	// Prints sorted array
	std::cout << "Sorted Array:   " << " ";
	printArray(arr, 10);
	std::cout << std::endl << "**************************************" << std::endl;

	// deleteNode() ///////////////////////////////////////////////////////
	// Creating test BST
	BST<int> t1;

	t1.insert(3);
	t1.insert(5);
	t1.insert(2);
	t1.insert(6);
	t1.insert(4);

	std::cout << "********** deleteNode() Test **********" << std::endl;

	// Prints original tree
	std::cout << "Original Tree: " << " ";
	t1.inOrderTraversal();
	std::cout << std::endl;

	//t1.deleteNode(2);

	// Prints post-delete tree
	std::cout << "New Tree:      " << " ";
	t1.inOrderTraversal();
	std::cout << std::endl;



	std::cout << std::endl << "***************************************" << std::endl;

	///////////////////////////////////////////////////////////////////////
	return 0;
}