#include "Human.hpp"
#include <iomanip>

int main()
{
	// Brain b;
	// std::cout << b.identify() << " is same : " << &b << std::endl;
	// Brain c(110,110,200);
	// std::cout << c.identify() << " is same : " << &c << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	Human bob;
	// bob.getBrain().setiq(200); Brain이 constant라서 불가능
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;

	// Human클래스의 멤버변수 Brain가 const형이고, get*()함수들이 const 멤버함수여서 가져올 수 있는 상황
	std::cout << std::setw(15) << "bob iq: " << bob.getBrain().getiq() << std::endl;
	std::cout << std::setw(15) << "bob eq: " << bob.getBrain().geteq() << std::endl;
	std::cout << std::setw(15) << "bob scale: " << bob.getBrain().getscale() << std::endl;

	return (1);
}
