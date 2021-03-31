#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	// static이지만 private member라서 접근 불가능
	// std::cout << Fixed::_fractional_bits << std::endl;
	return (0);
}
