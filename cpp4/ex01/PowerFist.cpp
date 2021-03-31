#include "PowerFist.hpp"

PowerFist::PowerFist()
	: AWeapon("Power Fist", 8, 50)
{
	// std::cout << "Power Fist created" << std::endl;
}

PowerFist::PowerFist(std::string name, int apcost, int damage)
	: AWeapon(name, apcost, damage)
{
	// std::cout << "Power Fist created" << std::endl;
}

PowerFist::PowerFist(const PowerFist &ref) :
	AWeapon(ref.getName(), ref.getAPCost(), ref.getDamage())
{
	// std::cout << "Power Fist created(copy)" << std::endl;
}

PowerFist &PowerFist::operator=(const PowerFist &ref)
{
	if (this == &ref)
		return (*this);
	this->setName(ref.getName());
	this->setDamage(ref.getDamage());
	this->setAPCost(ref.getAPCost());
	return (*this);
}

PowerFist::~PowerFist()
{
	// std::cout << "Power Fist distoryed" << std::endl;
}

void PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
