#include "Weapon.hpp"

Weapon::Weapon(string weapon)
{
	this->_type = weapon;
}

Weapon::~Weapon(){}

string Weapon::getType(){return (this->_type);}

void Weapon::setType(string weapon)
{
	this->_type = weapon;
}