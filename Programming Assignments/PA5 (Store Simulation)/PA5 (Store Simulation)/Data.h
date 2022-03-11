/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: PA5
* Date: March 5, 2022, March 10, 2022
* Description: A grocery store simulation utilizing queues.
*/

#pragma once

class Data
{
public:
	Data(const int newNumber = 0, const int newServTime = 0, const int newTotalTime = 0);

	// Getters
	int getNumber();
	int getServTime();
	int getTotalTime();

	// Setters
	void setNumber(int newNumber);
	void setServTime(int newTime);
	void setTotalTime(int newTime);

	// Operations
	void clear();

private:
	int customerNumber;
	int serviceTime;
	int totalTime;
};

