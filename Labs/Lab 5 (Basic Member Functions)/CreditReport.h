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
	// Constructors /////////////////////////////////////////////////////////////////////////
	CreditReport(int newCreditScore = 0, int newNumHardInquiries = 0, double newOldestAccountYears = 0.0, double newAverageAccountYears = 0.0, double newRealEstateDebt = 0.0, double newCreditCardDebt = 0.0, int newRealEstateAccounts = 0, int newCreditCardAccounts = 0, int newRetailCardAccounts = 0);

	// Destructor /////////////////////////////////////////////////////////////////////////
	~CreditReport();

	// Setters /////////////////////////////////////////////////////////////////////////
	void setCreditScore(int newCreditScore);
	void setNumHardInquiries(int newNumHardInquiries);
	void setOldestAccountYears(int newOldestAccountYears);
	void setAverageAccountYears(int newAverageAccountYears);
	void setRealEstateDebt(double newRealEstateDebt);
	void setCreditCardDebt(double newCreditCardDebt);
	void setRealEstateAccounts(int newRealEstateAccounts);
	void setCreditCardAccounts(int newCreditCardAccounts);
	void setRetailCardAccounts(int newRetailCardAccounts);

	// Getters /////////////////////////////////////////////////////////////////////////
	int getCreditScore();
	int getNumHardInquiries();
	double getOldestAccountYears();
	double getAverageAccountYears();
	double getRealEstateDebt();
	double getCreditCardDebt();
	int getRealEstateAccounts();
	int getCreditCardAccounts();
	int getRetailCardAccounts();

	// Operations /////////////////////////////////////////////////////////////////////////
private:
	int creditScore;
	int numHardInquiries;
	double oldestAccountYears;
	double averageAccountYears;

	// debt /////////////////////////////////////////////////////////////////////////
	double realEstateDebt;
	double creditCardDebt;

	// accounts /////////////////////////////////////////////////////////////////////////
	int realEstateAccounts;
	int creditCardAccounts;
	int retailCardAccounts;
};