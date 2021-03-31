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
		int a;
		virtual_A *clone() const;
};

virtual_A *A::clone() const
{
	A *temp = new A[2];
	temp[0].a = 20020;
	temp[1].a = 20021;
	cout << "virtual_A *A::clone() : 호출" << endl;
	return ((virtual_A *)temp);
}

int main()
{
	virtual_A *a;
	A test;

	a = test.clone();
	return (0);
}
