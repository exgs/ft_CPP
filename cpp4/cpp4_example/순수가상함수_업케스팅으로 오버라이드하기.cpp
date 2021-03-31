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
		A *clone() const;
};


A::A()
{
	;
}

A::A(const A &ref)
{
	;
}

// 반환형을 자식클래스로 바꿔보자 -> 가능하군
A *A::clone() const
{
	A *temp = new A(*this); //뭔가 이상하네
	temp->a =123;
	return (temp);
}

int main()
{
	A a;
	virtual_A *aa;
	aa = a.clone();
	cout << aa << endl;
	return (0);
}
