#include <iostream>

using namespace std;

class A
{
	protected :
		int _a;
		string _str;
	public:
		A(int a = 103, string str = "hello3"): _a(a), _str(str)
		{
			cout << "_a : " << _a << endl;
			cout << "_a : " << _str << endl;
			cout << "a : " << a << endl;
			cout << "a : " << str << endl;
			cout << "-=-=-=-=-=-=-=-=-=-=-=" << endl;
		};
};

class B : virtual public A
{
	public:
		B(int a = 102, string str = "hello2"): A(a,  str)
		{
			cout << "_b : " << _a << endl;
			cout << "_b : " << _str << endl;
			cout << "b : " << a << endl;
			cout << "b : " << str << endl;
			cout << "-=-=-=-=-=-=-=-=-=-=-=" << endl;
		};
};

class C : virtual public A
{
	public:
		C(int a = 101, string str = "hello1"): A(a,  str)
		{
			cout << "_c : " << _a << endl;
			cout << "_c : " << _str << endl;
			cout << "c : " << a << endl;
			cout << "c : " << str << endl;
			cout << "-=-=-=-=-=-=-=-=-=-=-=" << endl;
		};
};

class D : public C, public B // 하나만 상속이여도 독일한 문제발생
{
	public:
		D(int a = 100, string str = "hello0"): B(a, str), C(a, str)
		{
			cout << "_d : " << _a << endl;
			cout << "_d : " << _str << endl;
			cout << "d : " << a << endl;
			cout << "d : " << str << endl;
			cout << "-=-=-=-=-=-=-=-=-=-=-=" << endl;
		};
};

int main()
{
	B temp_B(23, "뭐");
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	C temp_C(32, "그래서");
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	D temp_D(23, "어쩌라고");
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	return (0);
}
