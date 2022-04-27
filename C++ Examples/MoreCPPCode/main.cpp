#include <iostream>
#include <list>

int main()
{
	int arr[5] = { 1,2,3,4,5 };

	for (auto i : arr) // range-based loop, foreach
	{
		std::cout << "element: " << i << std::endl;
	}

	std::list<int> ourList;
	
	ourList.push_back(10);
	ourList.push_back(42);
	ourList.push_front(50);

	for (std::list<int>::iterator it = ourList.begin(); it != ourList.end(); ++it)
	{
		std::cout << "element: " << *it << std::endl;
	}

	return 0;
}