#include "whatever.hpp"

int main(void)
{
	int a = 2;
	int b = 3;
	yunslee::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << yunslee::min( a, b ) << std::endl;
	std::cout << "max(a, b) = " << yunslee::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	yunslee::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << yunslee::min( c, d ) << std::endl;
	std::cout << "max(c, d) = " << yunslee::max( c, d ) << std::endl;
	return 0;
}
