// AO

// This example introduces inheritance. Note that
// the Manager class is derived from the Employee class

#include <iostream>
#include <string>

// Inheritance starter code! Not yet complete!

#include "Employee.h"
#include "Manager.h"

int main(void)
{

	Employee e1("Greg", 17.00, 45);
	Manager m1("Z", 31000.00, 60, true);

	cout << "Greg's pay: " << e1.calculatePay() << endl;
	cout << "Z's pay: " << m1.calculatePay() << endl;

	//m1.


	return 0;
}