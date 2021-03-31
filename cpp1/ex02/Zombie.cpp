#include "Zombie.hpp"

Zombie::Zombie(std::string type, std::string name)
{
	this->_name = name;
	this->_type = type;
	// 만약 생성되자마자 announce를 하는 것이라고 해석한다면, 여기서 announce()함수 호출. 나는 아니라고 봄.
}

Zombie::~Zombie()
{
	std::cout << "<" << gettype() << " (" << gettype() << ")> ";
	std::cout << "소멸자에 의해 죽었습니다." << std::endl ;
}

std::string Zombie::getname(){return (this->_name);}
std::string Zombie::gettype(){return (this->_type);}
void Zombie::settype(std::string type)
{
	this->_type = type;
}
void Zombie::setname(std::string name)
{
	this->_name = name;
}

void Zombie::announce()
{
	std::cout << "<" << getname() << " (" << gettype() << ")> ";
	std::cout << "Braiiiiiiinnnssss..." << std::endl;
}
