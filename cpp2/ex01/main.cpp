#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(10); // 객체 상수화!
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);
	// 생성자에는 반환형이 없는데도 불구하고, 임시 객체가 생성되는 것으로 보임.
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl; // d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;


	// 생성자(float a)에 showRawBits() 추가해서 확인하기~!!
	/* 추가 */

	std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
	std::cout.precision(40);
	float result2_value = -1;
	Fixed result2(result2_value); // 양수 음수 다 넣어보세요
	std::cout << "result2 is " << result2 << std::endl;
	std::cout << "result2(real) is " << result2_value << std::endl;
	std::cout << "result2 is " << result2.toInt() << " as integer" << std::endl;
	std::cout << "result2 is " << result2.tofloat() << " as float" << std::endl;
	
	std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
	std::cout << "실수부 오버플로" << std::endl;
	float result3_value = 0 + 0.99609375f; // 오버플로 직전 
	// 0.998046875 -> 당연히 고정소수점(8bit)에서 값을 제대로 담지 못함.
	std::cout.precision(40);
	std::cout << result3_value << std::endl;
	Fixed result3(result3_value);
	std::cout << "result3 is " << result3 << std::endl;
	std::cout << "result3(real) is " << result3_value << std::endl;
	std::cout << "result3 is " << result3.toInt() << " as integer" << std::endl;
	std::cout << "result3 is " << result3.tofloat() << " as float" << std::endl;

	float result4_value = 1 - 0.99609375f; // 오버플로 직전
	// 1 - 0.998046875 -> 당연히 고정소수점(8bit)에서 값을 제대로 담지 못함.
	std::cout.precision(40);
	std::cout << result4_value << std::endl;
	Fixed result4(result4_value);
	std::cout << "result4 is " << result4 << std::endl;
	std::cout << "result4(real) is " << result4_value << std::endl;
	std::cout << "result4 is " << result4.toInt() << " as integer" << std::endl;
	std::cout << "result4 is " << result4.tofloat() << " as float" << std::endl;

	std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
	std::cout << "정수부 오버플로" << std::endl;
	// -8388608 ~ 8388607 까지는 값의 누락이 없다.
	float result5_value = (float)8388607; // 오버플로 직전
	// 8388608 부터 오버플로 
	std::cout.precision(40);
	std::cout << result5_value << std::endl;
	Fixed result5(result5_value);
	std::cout << "result5 is " << result5 << std::endl;
	std::cout << "result5(real) is " << result5_value << std::endl;
	std::cout << "result5 is " << result5.toInt() << " as integer" << std::endl;
	std::cout << "result5 is " << result5.tofloat() << " as float" << std::endl;

	float result6_value = (float)-8388608; // 오버플로 직전
	// -8388609 부터 오버플로
	std::cout.precision(40);
	std::cout << result6_value << std::endl;
	Fixed result6(result6_value);
	std::cout << "result6 is " << result6 << std::endl;
	std::cout << "result6(real) is " << result6_value << std::endl;
	std::cout << "result6 is " << result6.toInt() << " as integer" << std::endl;
	std::cout << "result6 is " << result6.tofloat() << " as float" << std::endl;
	return (0);
}

