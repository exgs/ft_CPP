#include <iostream>
#include <string>

using namespace std;

class A
{
	public:
		int a;
	public:
		A();
		int geta() const; //virtual은 여기서 정의함. B 클래스에서 하는 것은 영향없음.
};

A::A()
{
	cout << &a << endl;
	a = 123;
}

class B : public A
{
	public:
		int a;
	public:
		B();
		int geta() const;
};

B::B() : A()
{
	cout << &a << endl;
	a = 321;
}

int A::geta() const
{
	cout << "A_geta() : " << &a << endl;
	cout << "A::a : " << A::a << endl;
	return (a);
}

int B::geta() const
{
	cout << "B_geta() : " << &a << endl;
	cout << "B::a : " << B::a << endl;
	cout << "A::a : " << A::a << endl;
	return (a);
}

int main()
{
	B hello;
	A *temp;
	temp = &hello;
	// B *tem;
	// tem = temp; 부모가 자식을 가리키는 것은 가능하지만, 자식이 부모를 가리키는 것은 불가능하다.
	// 포함관계가 다르니깐.
	cout << hello.geta() << endl;
	cout << temp->geta() << endl;

	cout << &hello.a << endl;
	cout << &temp->a << endl;
	return (0);
}
