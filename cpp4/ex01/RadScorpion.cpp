#include "RadScorpion.hpp"

RadScorpion::RadScorpion() :
	Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;	
}

RadScorpion::RadScorpion(const RadScorpion &ref) :
	Enemy(ref.getHP(), ref.getType())
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion& RadScorpion::operator=(const RadScorpion &ref)
{
	if (this == &ref)
		return (*this);
	this->setHP(ref.getHP());
	this->setType(ref.getType());
	std::cout << "[RadScorpion] assignation occured" << std::endl;
	return (*this);
}

void RadScorpion::takeDamage(int damage)
{
	if (this->getHP() <= 0)
	{
		// std::cout << "[takeDamage] enemy already died" << std::endl;
		return ;
	}
	damage -= 1; // Overriding한 이유!
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
