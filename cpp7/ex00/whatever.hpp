#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
// using namespace std;

namespace yunslee
{
	template <typename T>
	void swap(T &a, T &b)
	{
		T temp;
		temp = a;
		a = b;
		b = temp;
	}

	template <typename T>
	T min(T &a, T &b)
	{
		if (a < b)
			return (a);
		else
			return (b);
	}

	template <typename T>
	T max(T &a, T &b)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
}

class A
{
	public:
		int a;
		bool operator<(A &ref){return (this->a < ref.a);};
		bool operator>(A &ref){return (this->a > ref.a);};
		bool operator<=(A &ref){return (this->a <= ref.a);};
		bool operator>=(A &ref){return (this->a >= ref.a);};
};

class Awesome {
	public :
		Awesome( int n = 0) : _n( n ) {} // swap에서 기본생성자가 무조껀 필요하다.
		bool operator==( Awesome const & rhs ) { return (this->_n == rhs._n); } 
		bool operator!=( Awesome const & rhs ) { return (this->_n != rhs._n); } 
		bool operator>( Awesome const & rhs ) { return (this->_n > rhs._n); } 
		bool operator<( Awesome const & rhs ) { return (this->_n < rhs._n); } 
		bool operator>=( Awesome const & rhs ) { return (this->_n >= rhs._n); } 
		bool operator<=( Awesome const & rhs ) { return (this->_n <= rhs._n); }
		int getN(){return (this->_n);};
	private :
		int _n;
};

#endif
