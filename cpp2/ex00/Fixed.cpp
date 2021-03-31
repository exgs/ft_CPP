#include "Fixed.hpp"

// 만약, 멤버변수가 const이면, 생성자에서 초기화리스트를 써야함. _fractional_bits가 static이기 때문에 생성자에서 설정할 수 없다.
Fixed::Fixed(int value):
_value(value)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed &a)
{
	std::cout << "Copy constructor called" << std::endl;
	//case1
	*this = a;
	//case2 <-- This line may be missing depending on your implementation.
	// _value = a.getRawBits();
}

Fixed &Fixed::operator=(Fixed &a)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this == &a)
		return (*this);
	else
	{
		/* 객체 a의 클래스와 현재 멤버함수의 클래스가 같아서 a._value가 가능하다.
		_value = a._value;
		다만, 그러기보다는 private에 접근하는 것은 항상 함수로 하는 것이 캡슐화를 잘 구현했다고 볼 수 있을 듯 */

		_value = a.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const value)
{
	this->_value = value;
	return ;
}

