/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 5
* Date: February 16, 2022
* Description: Basic C++ Member Functions
*/

#pragma once

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class CreditReport
{
public:
	// Constructors
	CreditReport(int newCreditScore = 0, int newNumHardInquiries = 0, double newOldestAccountYears = 0.0, double newAverageAccountYears = 0.0, double newRealEstateDebt = 0.0, double newCreditCardDebt = 0.0, double newRealEstateAccounts = 0.0, double newCreditCardAccounts = 0.0, double newRetailCardAccounts = 0.0);
private:
	int creditScore;
	int numHardInquiries;
	double oldestAccountYears;
	double averageAccountYears;

	// debt
	double realEstateDebt;
	double creditCardDebt;

	// accounts
	int realEstateAccounts;
	int creditCardAccounts;
	int retailCardAccounts;
};