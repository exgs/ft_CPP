#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <array>
// using namespace std;

template <typename T1, typename T2>
void iter(T1* array, T2 length, void (*func)(T1 &))
{
	for (T2 i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

template <typename T1, typename T2>
void iter(T1* array, T2 length, void (*func)(T1 const &))
{
	for (T2 i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

#endif
