#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

// using namespace std;

class Fixed
{
	private:
		int _value;
		static int const _fractional_bits = 8;	//static은 전역변수, const니깐 초기값 설정
												//32bit 중에서 8bit를 소수부로 사용하겠다.
												// 2^24 = 16777216 만큼만 정수 부로 사용,
												// -8388608 ~ 8388607 까지는 값의 누락이 없다.
	public:
		Fixed();
		Fixed(int _value);
		Fixed(float value);
		~Fixed();
		Fixed(Fixed const &a); //복사함에 있어서 레퍼런스 a의 값 변화를 원하지 않기 때문에
		Fixed &operator=(Fixed const &a); // r-value와 타입이 맞는 것은 const 형임

		// Fixed &operator<<(Fixed &a); // 첫번째 인자를 객체자신을 받는 것이 default이기때문에, 멤버함수로 오버로딩하면 안된다.
		
		int getRawBits(void) const; // value를 return
		void setRawBits(int const raw);
		int toInt(void) const;
		float tofloat(void) const;

		// 내가 만든 함수
		int getFractionalBits(void) const; // value를 return
		void showRawBits(void) const;
};
std::ostream &operator<<(std::ostream& os, const Fixed &a); // 첫번째인자를 ostream을 받기위해서 class 외부함수로 정의됨.
#endif
