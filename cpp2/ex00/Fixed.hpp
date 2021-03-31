#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

// using namespace std;
class Fixed
{
	private:
		int _value;
		static const int _fractional_bits = 8; //static은 전역변수, const니깐 초기값 설정
		// 클래스에서 공통적으로 쓰는 고정된 값으로 메모리를 적게 쓴다는 장점이 있겠다. private이여서 외부에서 접근 불가능
	public:
		Fixed(int _value = 0);
		~Fixed();
		Fixed(Fixed &a);
		Fixed &operator=(Fixed &a);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
