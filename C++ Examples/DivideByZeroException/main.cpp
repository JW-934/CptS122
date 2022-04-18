#include "DivideByZeroException.h"

int divide(int n1, int n2);

int main()
{
	// volatile int num3; // used for values that are thought to be unable to be reached (I think)

	int num1 = 2, num2 = 1, result = 0;

	try
	{
		result = divide(num1, num2);
		cout << "result: " << result << endl;
	}
	catch (DivideByZeroException &dbz)
	{
		cout << dbz.what() << endl;
		cout << "take a different path for dividing the numbers!" << endl;
	}

	cout << "rest of program!" << endl;

	// Could use result and it would be incorrect

	return 0;
}

int divide(int n1, int n2)
{
	int result = 0;

	if (n2 != 0)
	{
		result = n1 / n2;
	}
	else // exception here, dividing by 0
	{
		//std::cout << "Dividing by 0!" << std::endl;
		throw DivideByZeroException();
	}
	return result; // if exception thrown, this return is skipped over
}