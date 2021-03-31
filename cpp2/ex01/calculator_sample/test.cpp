#include <iostream>
using namespace std;
#include <cmath>

class A
{
	int a  = 0; // 기본적으로 private에 저장되네요.
};

int main()
{
	// 2,147,483,647
	int a = 2147483647;
	int b = a << 1;
	cout << (int)b << endl;
	cout << "===========" << endl;
	float c = 0.5;
	// cout << c ** 2 << endl;
	cout << powf(c,1) << endl;
	
	/*
	int c = 1;
	cout << (c << 1) << endl;
	cout << (c << 1) << endl;
	*/

	return (0);
}
