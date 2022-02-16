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

	// r1 = r2.add(r4);
	r1 = r2 + r4;

	// r1 = r1;

	// cout << r1.getNumerator() << " / " << r1.getDenominator() << endl;
	cout << r1 << endl;

	ifstream infile;

	infile.open("RNumbers.txt", std::ios::in); // default mode is for read if none entered

	return 0;
}