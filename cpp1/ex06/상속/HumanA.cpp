#include "HumanA.hpp"

HumanA::HumanA(string name, string Weapon)
{
	this->_name = name;
	this->setType(Weapon);
}

HumanA::~HumanA(){}

void HumanA::attack()
{
	cout << this->getName() << " attacks with his " << this->getType() << endl;
}

string HumanA::getName(){return (this->_name);}

void HumanA::setName(string name){this->_name = name;}
