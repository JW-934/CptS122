#include <iostream>

int main()
{
	int arr[5] = { 1,2,3,4,5 };

	for (auto i : arr) // range-based loop, foreach
	{
		std::cout << "element: " << i << std::endl;
	}
	return 0;
}