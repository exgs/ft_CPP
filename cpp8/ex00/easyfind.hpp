#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

// using namespace std;

template<typename T, typename S>
typename T::iterator easyfind(T& container, S x)
{
	typename T::iterator found = std::find(container.begin(), container.end(), x);
	if (found == container.end())
		throw std::exception();
	return found;
}

// template<template <typename, typename> class T>
// typename T<int, std::allocator<int> >::iterator
// 	easyfind(T<int, std::allocator<int> >& container, int x)
// {
// 	typename T::iterator found = std::find(container.begin(), container.end(), x);
// 	if (found == container.end())
// 		throw std::exception();
// 	return found;
// }


/*
** easyfind_index
*/
template<typename T, typename S>
S easyfind_index(T& container, S x)
{
	int idx = 0;
	typename T::iterator it;
	for (it = container.begin(); it != container.end(); it++)
	{
		if (*it == x)
			return (idx);
		idx++;
	}
	if (it == container.end())
		throw std::exception();
	return (idx);
}
#endif
