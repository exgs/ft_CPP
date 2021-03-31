#include <iostream>

class A {
private:
    int A_num;
    int A_sum;
public:
    A() { printf("A 생성자\n"); }
    ~A() { printf("A 소멸자\n"); }
    void fun1() { printf("A의 fun1\n"); }
};

class B : public A {
private:
    int B_num;
    int B_sum;
public:
    B() { printf("B 생성자\n"); }
    ~B() { printf("B 소멸자\n"); }
    void fun2() { printf("B의 fun1\n"); }
};

int main(void) {
	A* a = new A();
	delete a;
	printf("------\n");
	B* b = new B();
	delete b;
	printf("------\n");

	A* c = new B(); // virtual ~A()가 아니라서, B소멸자는 호출되지 않았다.
	delete c;

	return 0;
}
