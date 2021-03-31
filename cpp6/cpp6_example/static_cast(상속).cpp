#include <iostream>
#include <string>

using namespace std;

class Parent{};
class Child : public Parent {};

int main()
{
	Parent P, *pP;
	Child C, *pC;
	int i = 1;

	pP = static_cast<Parent *>(&C); // 업 캐스팅
	pC = static_cast<Child *>(&P); // 다운 캐스팅

	// pP = static_cast<Parent *>(&i);
	// pC = static_cast<Child *>(&i);
	Parent &rp = static_cast<Parent &>(C);
	Child &rC = static_cast<Child &>(P);
	// 레퍼런스도 가능하네
	return (1);
}
