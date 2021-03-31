#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <list>
// using namespace std;

class span
{
	public:
		unsigned int max_size_;
		unsigned int size_;
		std::list<int> list_; // list 멤버함수중에 sort가 있음
	public :
		span();
		span(unsigned int size);
		span(span& ref);
		virtual ~span();
		span &operator=(span& ref);
		void addNumber(int num); // exception throw
		void addNumber(std::list<int>::iterator a, std::list<int>::iterator b); // exception throw
		unsigned int shortestSpan();
		unsigned int longestSpan();

	class addNumberException : public std::exception
	{
		public:
			const char * what() const _NOEXCEPT;
	};
	class maxSizeException : public std::exception
	{
		public:
			const char * what() const _NOEXCEPT;
	};
	class overFlowException : public std::exception
	{
		public:
			const char * what() const _NOEXCEPT;
	};
	class noNumberstored : public std::exception
	{
		public:
			const char * what() const _NOEXCEPT;
	};
};

#endif
