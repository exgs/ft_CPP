#include "easyfind.hpp"
#include <iostream>
#include <vector> // container
#include <list> // continaer
#include <queue>
#include <array>

// using namespace std;

template<typename IT>
void print_all(IT s, IT e)
{
	IT it;
	for (it=s; it!=e; it++)
	{
		std::cout << *it << std::endl;
	}
}



int main()
{
	std::deque<int> li;
	li.push_back(1);li.push_back(2);
	li.push_back(3);li.push_back(4);li.push_back(5);
	print_all(li.begin(), li.end());
	
	int find_what = 3;

	std::deque<int>::iterator it;
	try
	{
		it = easyfind(li, find_what);
		std::cout << " easyfind =-=-=-=-=-=-=-= " << std::endl;
		std::cout << "현재 값 : " << *(it) << std::endl;
		// 가능한 컨테이너가 있고 불가능한 컨테이너가 있다.
		// std::cout << "이전 값 : " << *(--it) << std::endl;
		// std::cout << "이후 값 : " << *(++it) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	std::cout << " easyfind_index =-=-=-=-=-=-=-= " << std::endl;
	int idx;
	try
	{
		idx = easyfind_index(li, find_what);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "idx number : " << idx << std::endl;
}
