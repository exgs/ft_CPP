#include <iostream>

using namespace std;

int main()
{
	int b = 123;
	int &c = b;
	int d;
	d = c;
	cout << &c << endl;
	cout << c << endl;
	cout << &d << endl;
	cout << d << endl;

	return (0);
}
// 레퍼런스 = 지역변수 (X) 할당 불가능, 초기화만 가능
// 지역변수 = 레퍼런스 (O) 가능함 -> 값복사로 오버로딩 됬나봄

/*
0x7ffeeacda7d8
123
0x7ffeeacda7cc
123
*/
