#include <iostream>

using namespace std;

int main()
{
	int min = -2147483648;
	int max = 2147483647;
	float f_max;
	float f_min;
	long long_max;
	long long_min;

	cout << sizeof(long) << endl; // 8byte
	cout << sizeof(int) << endl; // 4byte

	f_min = static_cast<float>(min);
	f_max = static_cast<float>(max);
	cout << --f_min << endl; 
	cout << ++f_max << endl;

	long_min = static_cast<long>(min);
	long_max = static_cast<long>(max);
	cout << --long_min << endl;
	cout << ++long_max << endl;

	long d = -2147483648 -2147483648;
	cout << --d << endl;

	// 두 방법 모두 부호를 정확하게 가지고 있음. long이 조금 더 안전해보인다.
	return (1);
}
