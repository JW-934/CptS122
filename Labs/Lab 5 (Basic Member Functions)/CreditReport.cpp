/*
* Programmer: Jesse Watson
* Class: CptS 122, Spring 2022; Lab Section 6
* Assignment: Lab 5
* Date: February 16, 2022
* Description: Basic C++ Member Functions
*/

#include "CreditReport.h"

// Constructors /////////////////////////////////////////////////////////////////////////
CreditReport::CreditReport(int newCreditScore, int newNumHardInquiries, double newOldestAccountYears, double newAverageAccountYears, double newRealEstateDebt, double newCreditCardDebt, int newRealEstateAccounts, int newCreditCardAccounts, int newRetailCardAccounts)
{
	creditScore = newCreditScore;
	numHardInquiries = newNumHardInquiries;
	oldestAccountYears = newOldestAccountYears;
	averageAccountYears = newAverageAccountYears;
	realEstateDebt = newRealEstateDebt;
	creditCardDebt = newCreditCardDebt;
	realEstateAccounts = newRealEstateAccounts;
	creditCardAccounts = newCreditCardAccounts;
	retailCardAccounts = newRetailCardAccounts;
}

// Destructor //////////////////////////////////////////////////////////////////////////
CreditReport::~CreditReport()
{

}

// Setters /////////////////////////////////////////////////////////////////////////////
void CreditReport::setCreditScore(int newCreditScore)
{
	creditScore = newCreditScore;
}

void CreditReport::setNumHardInquiries(int newNumHardInquiries)
{
	numHardInquiries = newNumHardInquiries;
}

void CreditReport::setOldestAccountYears(int newOldestAccountYears)
{
	oldestAccountYears = newOldestAccountYears;
}

void CreditReport::setAverageAccountYears(int newAverageAccountYears)
{
	averageAccountYears = newAverageAccountYears;
}

void CreditReport::setRealEstateDebt(double newRealEstateDebt)
{
	realEstateDebt = newRealEstateDebt;
}

void CreditReport::setCreditCardDebt(double newCreditCardDebt)
{
	creditCardDebt = newCreditCardDebt;
}

void CreditReport::setRealEstateAccounts(int newRealEstateAccounts)
{
	realEstateAccounts = newRealEstateAccounts;
}

void CreditReport::setCreditCardAccounts(int newCreditCardAccounts)
{
	creditCardAccounts = newCreditCardAccounts;
}

void CreditReport::setRetailCardAccounts(int newRetailCardAccounts)
{
	retailCardAccounts = newRetailCardAccounts;
}

// Getters /////////////////////////////////////////////////////////////////////////////
int CreditReport::getCreditScore()
{
	return creditScore;
}

int CreditReport::getNumHardInquiries()
{
	return numHardInquiries;
}

double CreditReport::getOldestAccountYears()
{
	return oldestAccountYears;
}

double CreditReport::getAverageAccountYears()
{
	return averageAccountYears;
}

double CreditReport::getRealEstateDebt()
{
	return realEstateDebt;
}

double CreditReport::getCreditCardDebt()
{
	return creditCardDebt;
}

int CreditReport::getRealEstateAccounts()
{
	return realEstateAccounts;
}

int CreditReport::getCreditCardAccounts()
{
	return creditCardAccounts;
}

int CreditReport::getRetailCardAccounts()
{
	return retailCardAccounts;
}

// Operations //////////////////////////////////////////////////////////////////////////////////