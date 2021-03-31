#include "Fixed.hpp"

/* 생성자 */
Fixed::Fixed():_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = (value << _fractional_bits);
}

Fixed::Fixed(float value)
{
	std::cout << "Float constructor called" << std::endl;
	_value = 0;
	int integer = (int)roundf(value);
	float only_fraction;
	if (value - integer < 0) // 23.6 - 24
	{
		_value = (integer - 1) << _fractional_bits; // 23
		only_fraction = value - (integer - 1); // 0.6
	}
	else
	{ // 23.3 - 23 
		_value = integer << _fractional_bits; // 23
		only_fraction = value - integer; // 0.3
	}
	// cout << "integer:" << integer << endl;
	// cout << "value:" << _value << endl;
	// cout << "return: value:" << (_value >> _fractional_bits) << endl;
	// cout << "only_fraction : " << only_fraction << endl;
	int count = 8;
	for (int i = 0; i < count; i++)
	{
		float z = powf(0.5, i + 1);
		if (z <= only_fraction)
		{
			_value += (1 << (count - i - 1));
			only_fraction -= z;
		}
		this->showRawBits();
	}
}

/* 나 개인적으로는 더 맞는 거 같다. 초기화를 쓰니깐.*/
// Fixed::Fixed(Fixed const &a):_value(a.getRawBits())
// {
// 	std::cout << "Copy constructor called" << std::endl;
// }

Fixed::Fixed(Fixed const &a)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = a; // =연산자 오버로딩 사용!
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/* =연산자 오버로드 */
Fixed &Fixed::operator=(Fixed const &a)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this == &a)
		return (*this);
	else
	{
		_value = a.getRawBits();
	}
	return (*this);
}

std::ostream &operator<<(std::ostream& os, const Fixed &a)
{
	std::cout << a.tofloat();
	return (os);
}

/* set get */
int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const value)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_value = value;
	return ;
}

int Fixed::getFractionalBits(void) const
{
	return (_fractional_bits);
}

/* 변환 */
int Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->getFractionalBits());
}

float Fixed::tofloat(void) const
{
	float ret = 0;
	//---정수 부분 더하기---
	ret += this->toInt();
	//---소수 부분 더하기---
	// cout << _value - (this->toInt() << this->getFractionalBits()) << endl;
	int count = 8;
	for (int i = 0; i < count; i++)
	{
		if ((1 << (count - i - 1)) & _value)
		{
			ret += powf(0.5, i + 1);
		}
	}

	return (ret);
}

/* print 툴 */
void Fixed::showRawBits(void) const
{
	int count = 32;
	for (int i = 1; i < count + 1; i++)
	{
		if ((1 << (32 - i)) & _value)
			std::cout << "1";
		else
			std::cout << "0";
		if (i % 8 == 0)
			std::cout << " ";
	}
	std::cout << std::endl;
}

