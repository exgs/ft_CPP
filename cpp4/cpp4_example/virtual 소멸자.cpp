#include <iostream>
using namespace std;

class IA
{
	public:
		IA(){cout << "IA" << endl;};
		virtual ~IA(){cout << "~IA" << endl;};
};

class A : public IA
{
	public:
		A(){cout << "A" << endl;};
		~A(){cout << "~A" << endl;};
};

int main()
{
	A a; // virtual이 없어도 자식,부모 소멸자가 잘 호출됨

	IA *b = new A; // 부모 소멸자만 호출되고 자식 소멸자는 호출되지않음.
	delete b; // 이거 없으면 b에 대한 소멸자가 호출되지 않음.(프로그램 종료되면서 할당해제 될지는 몰라도)
	return (1);
}
