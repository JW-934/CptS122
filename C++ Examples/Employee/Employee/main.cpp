// AO

// This example introduces inheritance. Note that
// the Manager class is derived from the Employee class

#include <iostream>
#include <string>

// Inheritance starter code! Not yet complete!

#include "Employee.h"
#include "Manager.h"

void printPay(Employee& emp);

int main(void)
{
	Employee e1("Greg", 17.01, 45);
	Manager m1("Z", 31000.00, 60, true);

	Employee* pE1 = new Employee("Greg", 17.00, 45);
	Manager* pM1 = new Manager("Zviko", 31000.00, 60, true);
	//Manager* pM2 = new Employee("Zviko", 31000.00, 60);
	Employee* pE2 = new Manager("Greg", 17.00, 45, true);

	Employee* pEArr[100] = { nullptr };
	int option = 0;
	int index = 0;

	cout << "Enter the number of employees to add to our Employee system: ";
	cin >> option;

	while (index < option)
	{
		int empType = 0;
		cout << "What type of Employee? (1) Standard (2) Manager ";
		cin >> empType;
		switch (empType)
		{
		case 1: pEArr[index] = new Employee();
			break;
		case 2: pEArr[index] = new Manager();
			break;
		}

		printPay(*pEArr[index]);
		delete pEArr[index];
		++index;
	}

	//printPay(*pE1);
	//printPay(*pE2);

	//cout << "Greg's pay: " << pE1->calculatePay() << endl;
	//cout << "Greg's pay: " << pE2->calculatePay() << endl; // this only works because of virtual before calculatePay();
	//cout << "Z's pay: " << pM1->calculatePay() << endl;

	/*cout << "Greg's pay: " << e1.calculatePay() << endl;
	cout << "Z's pay: " << m1.calculatePay() << endl;*/

	//m1.


	return 0;
}

void printPay(Employee& emp)
{
	cout << "Pay: " << emp.calculatePay() << endl;
}