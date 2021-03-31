#include <iostream>
using namespace std;
int main()
{
	int a =123;
	int &b = a;
	const int &c = b;
	b = 1;
	cout << "b : " << b << endl;
	cout << "c : " << c << endl;
	return (0);
}
