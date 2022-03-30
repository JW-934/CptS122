#include "Manager.h"

Manager::~Manager()
{
	cout << "Inside Manager Destructor?" << endl;
}

double Manager::calculatePay()
{
	double pay = 0.0;

	if (this->mIsSalaried)
	{
		// the manager is a salaried employee
		pay = this->getPayRate();
	}
	else
	{
		// hourly manager
		pay = this->Employee::calculatePay();
	}
	return pay;
}