/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 10
* Date: April 6, 2022
* Description: Implementation of merge sort and a BST template
*/

#include "MergeSort.h"

int main()
{
	int arr[15] = {3, 5, 2, 6, 4, 8, 4, 9, 0, 1};

	// Prints original array
	std::cout << "Original Array: " << " ";
	printArray(arr, 10);
	std::cout << std::endl;

	mergeSort(arr, 0, 9);

	// Prints sorted array
	std::cout << "Sorted Array:   " << " ";
	printArray(arr, 10);
	std::cout << std::endl;

	return 0;
}