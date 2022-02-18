// This example will allow us to explore
// classes, data members, member functions,
// constructor, destructors, function overloading,
// operator overloading, etc. We are building
// these ideas around a Rational object

// History: 

#include "Rational.h"

int main(void)
{
	Rational r1(0, 1), r2(5, 2), r3, r4(7);

	int n1 = 42, n2 = 10;

	cout << n1 - n2 << endl;

	cout << r2 - r3 << endl;

	// r1 = r2.add(r4);
	r1 = r2 + r4;

	// r1 = r1;

	// cout << r1.getNumerator() << " / " << r1.getDenominator() << endl;
	cout << r1 << endl;

	ifstream infile;

	infile.open("RNumbers.txt", std::ios::in); // default mode is for read if none entered

	/*int num = 0, den = 0;
	char slash;

	infile >> num;
	infile >> slash;
	infile >> den;*/

	/*r1.setNumerator(num);
	r1.setDenominator(den);*/

	infile >> r1 >> r2;

	cout << "r1: " << r1 << " r2: " << r2 << endl;

	infile.close();

	return 0;
}