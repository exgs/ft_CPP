#include "HumanB.hpp"

HumanB::HumanB(string name, string Weapon)
{
	this->_name = name;
	this->setType(Weapon); // _weapon이 private->public 으로 상속 받았기때문ㅇ
}

HumanB::~HumanB(){}

void HumanB::attack()
{
	cout << this->getName() << " attacks with his " << this->getType() << endl;
}

string HumanB::getName(){return (this->_name);}

void HumanB::setName(string name){this->_name = name;}
