#include "Zombie.hpp"

Zombie::Zombie(std::string type, std::string name)
{
	this->_name = name;
	this->_type = type;
}

Zombie::~Zombie(){}

Zombie &Zombie::operator=(const Zombie& op)
{
	if (this == &op)
		return (*this);
	this->_name = op._name;
	this->_type = op._type;
	return (*this);
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
