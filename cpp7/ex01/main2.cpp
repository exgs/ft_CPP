#include "iter.hpp"

template <typename T>
void func(T &ref)
{
	ref++;
}

template <typename T, int length>
void print_all(T *a)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << a[i] << std::endl;
	}
}

int main()
{
	// std::array<int, 10> a= {0,0,0,0,0,0,0,0,0,0};
	// std::array<size_t, 10> b= {0,0,0,0,0,0,0,0,0,0};
	// ::iter<std::array<int, 10>, int> (a, (int)a.size(), func<std::array<int, 10> >);
	// ::iter<size_t, size_t>(a, a.size(), func);
	int array[3] = {0,0,0};

	// iter<int, size_t>(array, 3, func); // ambiguous error
	iter<int, size_t>(array, 3, func<int>); // no error
	print_all<int, 3>(array);
	return (1);
}

