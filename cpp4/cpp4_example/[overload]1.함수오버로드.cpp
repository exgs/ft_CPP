#include <iostream>

using namespace std;

class A
{
	public:
		int num;
		A(): num(111){};
		A(int &getvalue): num(getvalue){};
		~A(){};
		A(int getvalue): num(getvalue){};

		// void getA(int getvalue);			// getvalue가 변경 될 수 없음
		// void getA(int const getvalue);	// getvalue가 변경 될 수 없음
		void getA(int &getvalue);			// getvalue가 변경 될 수 있음!
		void getA(const int &getvalue);	// getvalue가 변경 될 수 없음
		/* 포인터 추가 해보자 */
		void getA(int *getvalue);			// getvalue가 변경 될 수 있음!
};

void getA(int *getvalue)
{
	;
}

// void A::getA(int getvalue)
// {
// 	cout << "(int)getvalue : " << &getvalue << endl;
// };

// void A::getA(int const getvalue)
// {
// 	cout << "(const int)getvalue : " << &getvalue << endl;
// };

void A::getA(int &getvalue)
{
	cout << "(int &)getvalue : " << &getvalue << endl;
};

void A::getA(const int &getvalue)
{
	cout << "(const int &)getvalue : " << &getvalue << endl;
};

int main()
{
	int c = 20202;
	int &b = c;
	// 생성자의 오버로드를 보고 싶었어
	A *temp = new A;
	A *temp1 = new A(23);
	// A *temp2 = new A(b);

	// 함수의 오버로드를 보자. 어짜피 동일한 것 일테니깐.
	temp->getA(123);
	temp->getA(b);

	delete temp;
	delete temp1;
	// delete temp2;
	return (0);
}
