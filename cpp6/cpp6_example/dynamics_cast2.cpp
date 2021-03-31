// Parent *에 대입
#include <iostream>

using namespace std;

// class Parent{virtual void f(){};}; //가상함수가 있냐 없냐에 따라서 컴파일이 되기도하고 안되기도하는구나.
// class Parent{void f(){};};

class Parent{public: virtual ~Parent(){};}; // virtual 소멸자도 가상함수로 쳐줘서 dynamic casting이 되게함.
class Child : public Parent {};

int main()
{
	Parent P, *pP, *pP2;

	Child C, *pC, *pC2;
	pP = &P;
	// if ((pC2 = dynamic_cast<Parent *>(pP))) // 업케스팅 , lvalue타입과 <new_type>이 다르면 어떻하자는거지?
		// cout << "0" << endl; //ok
	if ((pC2 = dynamic_cast<Child *>(pP)))
		cout << "1" << endl; //ok

	pP = &P;
	if ((pP2 = dynamic_cast<Parent *>(pP)))
		cout << "2" << endl; // x
	if ((pP2 = dynamic_cast<Child *>(pP)))
		cout << "3" << endl; //o

	pP = &C;
	if ((pP2 = dynamic_cast<Parent *>(pP)))
		cout << "4" << endl; //x
	if ((pP2 = dynamic_cast<Child *>(pP)))
		cout << "5" << endl; //x
}
