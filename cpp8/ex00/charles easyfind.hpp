#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

// vector<int> src;
template<typename T, typename S = int>
S& easyfind(T& container, S x)
{
	typename T::iterator found = std::find(container.begin(), container.end(), x);
	if (found == container.end())
		throw std::exception();
	return *found;
}

#endif
