#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

// using namespace std;

template <typename T>
class Array
{
	private:
		T *array;
		unsigned int size_;
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &);
		virtual ~Array();
		Array &operator=(Array const &ref);
		T &operator[](int i);
		T &operator[](size_t i);
		unsigned int size() const;

	class ArrayException : public std::exception
	{
		public:
			const char* what() const _NOEXCEPT;
	};
};
#include "Array.cpp"
#endif
