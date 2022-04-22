#include <vector>
#include "DivideByZeroException.h"

using std::vector;

int divide(int n1, int n2);

int main()
{
	// volatile int num3; // used for values that are thought to be unable to be reached (I think)

	vector<int> v1;

	/*v1.push_back(5);
	v1.push_back(10);

	cout << "v[1]: " << v1[1] << endl;
	cout << "v[2]: " << v1[2] << endl;*/


	int num1 = 2, num2 = 0, result = 0;

	try
	{
		v1.push_back(5);
		v1.push_back(10);

		/*cout << "v[1]: " << v1[1] << endl;
		cout << "v[2]: " << v1[2] << endl;*/

		cout << "v.at(2): " << v1.at(2) << endl;

		result = divide(num1, num2);
		cout << "result: " << result << endl;
	}
	catch (DivideByZeroException &dbz)
	{
		cout << dbz.what() << endl;
		cout << "take a different path for dividing the numbers!" << endl;
	}
	/*catch (std::out_of_range &oor)
	{
		cout << oor.what() << endl;
	}*/
	catch (...) // Catch all other exceptions
	{
		cout << "catch all" << endl;
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