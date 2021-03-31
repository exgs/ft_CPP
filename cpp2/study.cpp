#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float a = 2.56;
	float b = roundf(a); // 소수 첫째자리에서 반올림

	std::cout << a << endl;
	std::cout << b << endl;
	
	// float c = roundf(2.56, 1); // 소수 첫째자리에서 반올림 없음
	float c = roundf(42.42f);
	std::cout << c << endl;

}
