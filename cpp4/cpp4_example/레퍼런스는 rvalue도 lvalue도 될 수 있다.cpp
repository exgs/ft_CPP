#include <iostream>
using namespace std;
int main()
{
	int a = 123123;
	int &b = a; // 레퍼런스는 rvalue가 아니라, lvalue를 할당받는 녀석인거 같음.
	int *c = &a; // 포인터도 주소값이라는 rvalue를 할당 받는거 같음.
	
	int d = b; // Rvalue 처럼 동작함
	int &f = b; // Lvalue 처럼 동작함

	cout << "d : " << d << endl;
	cout << "f : " << f << endl;

	/* 추가
	const int a = 123;
	int &b = a; // -> const value를 변경할 수 있는 레퍼런스로 binding하려고해서 나타나는 문제!
	int &c = 123; // 참조는 lvalue로 초기화를 진행하는데, 123은 rvalue(temporary)
	int d = 321;
	const int b = d;

	const int &asdf1 = 123;
	int &asdf2 = 123;

	// 헤답
	//https://www.notion.so/r-value-l-value-reference-530ce09461944364b93994dd81a4f3ba
	*/
	return (0);
}
