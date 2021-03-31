#include <iostream>

using namespace std;

int main()
{
	int num = 5;
	float real = 0;
	real = *(reinterpret_cast<float *>(&num));
	cout << real << endl;

	char a = 'd';

	// 공간이 있어야 할당이 된다.!!
	char *d = new char;
	*d = *(reinterpret_cast<char *>(&a));

	// 이것도 가능. !!
	// char d;
	// d = *(reinterpret_cast<char *>(&a));

	cout << d << endl;
	
	return (0);
}
