#include <iostream>
#include <string>

using namespace std;


class virtual_A
{
	public:
		virtual virtual_A *clone() const = 0;
};

class A : public virtual_A
{
	public:
		A();
		A(const A &ref);
		int a;
		virtual_A *clone() const;
		virtual_A *clone(double) const;
		int *clone(int a) const;
};

A::A()
{
	;
}

A::A(const A &ref)
{
	;
}

//정석
virtual_A *A::clone() const
{
	cout << "virtual function of clone" << endl;
	return (new A(*this));
}

virtual_A *A::clone(double) const
{
	cout << "overload virtual function of clone" << endl;
	return (new A(*this));
}

int *A::clone(int) const
{
	cout << "new function of clone" << endl;
	return (new int);
}


int main()
{
	A a;
	virtual_A *aa;
	aa = a.clone();
	cout << aa << endl;
	aa = a.clone(12.23);
	cout << aa << endl;

	int *b = a.clone(123);
	return (0);
}
