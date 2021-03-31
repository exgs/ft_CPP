#include "SuperMutant.hpp"

SuperMutant::SuperMutant() :
	Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant &ref) :
	Enemy(ref.getHP(), ref.getType())
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh..." << std::endl;
}

SuperMutant& SuperMutant::operator=(const SuperMutant &ref)
{
	if (this == &ref)
		return (*this);
	this->setHP(ref.getHP());
	this->setType(ref.getType());
	std::cout << "[SuperMutant] assignation occured" << std::endl;
	return (*this);
}

void SuperMutant::takeDamage(int damage)
{
	if (this->getHP() <= 0)
	{
		// std::cout << "[takeDamage] enemy already died" << std::endl;
		return ;
	}
	damage -= 3; // Overriding한 이유!
	if (damage < 0)
	{
		// std::cout << "[takeDamage] damage is zero" << std::endl;
		return ;
	}
	this->setHP(this->getHP() - damage);
	// std::cout << "[takeDamage] damage is " << damage << std::endl;
	if (this->getHP() <= 0)
	{
		// std::cout << "[takeDamage] enemy is now died" << std::endl;
		this->setHP(0);
		return ;
	}
}
