#include <iostream>

class A {
public:
	A() { printf("A 생성자\n"); }
	~A() { printf("A 소멸자\n"); }
	int num;
	virtual void stay() { printf("A stay\n"); }
	// virtual void stay() = 0; // 순수 가상 함수 => 추상 클래스가 됨.
};

// class B : public A {
class B : virtual public A {
public:
	B() { printf("B 생성자\n"); }
	~B() { printf("B 소멸자\n"); }
	// virtual void stay(){printf("B stay\n");}
	int num;
};

// class C : public A {
class C : virtual public A {
public:
	C() { printf("C 생성자\n"); }
	~C() { printf("C 소멸자\n"); }
	virtual void stay(){printf("C stay\n");}
	int num;
};

// class D : public B, public C{
class D : virtual public B, virtual public C{
public:
	D() { printf("D 생성자\n"); }
	~D() { printf("D 소멸자\n"); }
	// virtual void stay(){printf("D stay\n");}
	int num;
};

int main(void) {

	D d;
	d.num = 123;
	d.A::num = 2;
	d.B::num = 2;
	d.C::num = 2;
	d.D::num = 2;
	std::cout << "변수" << std::endl;
	d.stay();
	d.A::stay();
	d.B::stay();
	d.C::stay();
	d.D::stay();
	std::cout << "end" << std::endl;
	return 0;
}
