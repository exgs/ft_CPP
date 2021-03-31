#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle()
	: AWeapon("Plasma Rifle", 5, 21)
{
	// std::cout << "Plasma Rifle created" << std::endl;
}

PlasmaRifle::PlasmaRifle(std::string name, int apcost, int damage)
	: AWeapon(name, apcost, damage)
{
	// std::cout << "Plasma Rifle created" << std::endl;
}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &ref)
	: AWeapon(ref.getName(), ref.getAPCost(), ref.getDamage())
{
	// std::cout << "Plasma Rifle created(copy)" << std::endl;
}

PlasmaRifle &PlasmaRifle::operator=(const PlasmaRifle &ref)
{
	if (this == &ref)
		return (*this);
	this->setName(ref.getName());
	this->setDamage(ref.getDamage());
	this->setAPCost(ref.getAPCost());
	return (*this);
}

PlasmaRifle::~PlasmaRifle()
{
	// std::cout << "Plasma Rifle distoryed" << std::endl;
}

void PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
