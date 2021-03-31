#include <iostream>
#include <list>
#include <vector>

using namespace std;

template <typename T>
class A
{
	public :
		T a;
		template <typename S, int F = 1000>
		void test1(S a)
		{
			a = F;
			cout << a << endl;
		}
		template <int F = 1000>
		void test2()
		{
			a = F;
			cout << a << endl;
		}
		// template <typename S>
		// void add(S a)
		// {
		// 	cout << a << endl;
		// }
};


int main()
{	
	A<int> hello;
	hello.test1<int>(22323);
	hello.test1<int, 100>(23223);
	hello.test2<1>();

	return (1);
}
