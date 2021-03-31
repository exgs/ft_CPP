#include "HumanB.hpp"

HumanB::HumanB(const std::string& name)
:
    _weapon(),
    _name(name)
{}

HumanB::HumanB(const HumanB& copy)
:
    _weapon(copy._weapon),
    _name(copy._name)
{}

HumanB::~HumanB() {}

HumanB &HumanB::operator=(const HumanB& op)
{
    if (this == &op)
        return (*this);
    this->_weapon = op._weapon;
    this->_name = op._name;
    return (*this);
}

void    HumanB::setWeapon(Weapon& weapon) { this->_weapon = &weapon; }
void    HumanB::attack() { std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl; }
