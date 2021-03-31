#include <iostream>
using namespace std;

class Parent
{
	public:
	virtual void foo() //레퍼런스에서도 포인터 처럼 먹힘.!!
	{
		cout << "Class Parent" << endl;
	}
};

class Child : public Parent
{
	public:
		int a;
		int b;
		int c;
		int d;
	void foo()
	{
		cout << "Class Child" << endl;;
	}
};

class A
{
	public:
		int a;
		int b;
		int c;
		int d;
};

int main()
{
	// Parent pointer = Child(); // 완전 이상한 방식
	// pointer.foo();
	// Parent a = Parent();	복사생성자가 정의되어있지 않아서 8byte만 할당하나보다.
	// Parent b = Child(); 복사생성자가 정의되어있지 않아서 8byte만 할당하나보다.

	//
	Child b;
	Parent &d = b;
	Parent *reference = new Child;
	reference->foo();
	b.foo();
	d.foo();
	//
	Parent a;	
	A c;
	cout << " 크기 비교 " << endl;
	cout << sizeof(a) << endl;
	cout << sizeof(b) << endl;
	cout << sizeof(c) << endl;
	cout << sizeof(d) << endl;
	delete reference;
	return 0;
}
