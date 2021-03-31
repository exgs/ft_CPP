#include <vector>
#include <iostream>
int main()
{
	int array[100];
	int count = 100;
	for (size_t i = 0; i < count; i++)
	{
		array[i] = i * i;
	}
	
	std::vector<int> a;
	for (size_t i = 0; i < count; i++)
	{
		a.push_back(array[i]);
	}

	std::vector<int>::iterator it;
	for (it = a.begin(); it != a.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	return (1);
}
