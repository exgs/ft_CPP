#include <iostream>

using namespace std;

class A
{
	public :
		int a;
		~A(){cout << "소멸자 호출" << endl;};
};

int main()
{
	A *temp = new A;
	int a = 123;
	delete temp; // delete를 해주지 않으면 소멸자가 호출되지 않는다.
	return (1);
}
