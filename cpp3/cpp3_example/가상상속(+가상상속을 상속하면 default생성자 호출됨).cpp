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

class C : public A // 여기에 virtual을 쓰느냐 안쓰냐에 따라서 D가 달라짐.!!
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
		// A(int a = 103, string str = "hello3")
		// {

		// };
};

class D : virtual public C
{
	public:
		D(int a = 100, string str = "hello0"): C(a, str)
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
	C temp1(555, "그래서");
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	D temp(23, "뭐");
	return (0);
}
