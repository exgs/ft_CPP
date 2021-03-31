#include <iostream>
using namespace std;

class A
{
	public:
		int a;
		int &get_value();
};


int &A::get_value()
{
	cout << &(this->a) << endl;
	return (this->a);
}

int main()
{
	A abc;
	abc.a =23;
	// int *b = &(abc.get_value());
	int &b = abc.get_value();
	cout << b << endl;
	cout << &b << endl;
	cout << abc.a << endl;
	cout << &(abc.a) << endl;
}

/*
0x7ffee3b27738
23
0x7ffee3b27738
23
0x7ffee3b27738
*/
