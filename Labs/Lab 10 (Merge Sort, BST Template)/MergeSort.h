/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 10
* Date: April 6, 2022
* Description: Implementation of merge sort and a BST deleteNode() template
*/

#pragma once

#include <iostream>

// This code is heavily derived from geeksforgeeks.org/merge-sort/

// Splits an array into two subarrays
template <class T>
void merge(T arr[], int const left, int const mid, int const right);

template <class T>
void merge(T arr[], int const left, int const mid, int const right)
{
	int leftLen = mid - left + 1, rightLen = right - mid;

	//T leftArr[leftLen], rightArr[rightLen];

	T* leftArr = new T[leftLen], * rightArr = new T[rightLen];

	// Copy elements from original array to left and right subarrays
	for (int i = 0; i < leftLen; ++i)
	{
		leftArr[i] = arr[left + i];
	}
	for (int j = 0; j < rightLen; ++j)
	{
		rightArr[j] = arr[mid + j + 1];
	}

	int leftArrIndex = 0, rightArrIndex = 0, mergedArrIndex = left;

	// Merge subarrays back into original array
	while (leftArrIndex < leftLen && rightArrIndex < rightLen)
	{
		if (leftArr[leftArrIndex] <= rightArr[rightArrIndex])
		{
			arr[mergedArrIndex] = leftArr[leftArrIndex];
			++leftArrIndex;
		}
		else
		{
			arr[mergedArrIndex] = rightArr[rightArrIndex];
			++rightArrIndex;
		}
		++mergedArrIndex;
	}

	// Copies over any remaining elements
	while (leftArrIndex < leftLen)
	{
		arr[mergedArrIndex] = leftArr[leftArrIndex];

		++mergedArrIndex;
		++leftArrIndex;
	}
	while (rightArrIndex < rightLen)
	{
		arr[mergedArrIndex] = rightArr[rightArrIndex];

		++mergedArrIndex;
		++rightArrIndex;
	}

	delete[] leftArr;
	delete[] rightArr;
}

// Sorts an array of type T from least to greatest
template <class T>
void mergeSort(T arr[], int const start, int const end);

template <class T>
void mergeSort(T arr[], int const start, int const end)
{
	T middle;

	if (start >= end)
	{
		return;
	}
	middle = start + (end - start) / 2;
	mergeSort(arr, start, middle);
	mergeSort(arr, middle + 1, end);
	merge(arr, start, middle, end);
}

// Prints array to screen
template <class T>
void printArray(T arr[], int size);

template <class T>
void printArray(T arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
}