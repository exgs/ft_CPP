#include "AWeapon.hpp"

AWeapon::AWeapon() :
	apcost_(0), damage_(0), name_("null")
{
	// std::cout << "AWeapon created" << std::endl;
}

AWeapon::AWeapon(const std::string &name, int apcost, int damage) :
	apcost_(apcost), damage_(damage), name_(name)
{
	// std::cout << "AWeapon created" << std::endl;
}

AWeapon::AWeapon(const AWeapon &ref) :
	apcost_(ref.apcost_), damage_(ref.damage_), name_(ref.name_)
{
	// std::cout << "AWeapon created(copy)" << std::endl;
}
	
AWeapon &AWeapon::operator=(const AWeapon &ref)
{
	if (this == &ref)
		return (*this);
	apcost_ = ref.apcost_;
	damage_ = ref.damage_;
	name_ = ref.name_;
	return (*this);
}
	
AWeapon::~AWeapon()
{
	std::cout << "AWeapon destoryed" << std::endl;
}

std::string const AWeapon::getName() const{return (name_);}

int AWeapon::getAPCost() const{return (apcost_);}

int AWeapon::getDamage() const{return (damage_);}

void AWeapon::setName(std::string name){this->name_ = name;}

void AWeapon::setAPCost(int apcost){this->apcost_ = apcost;}

void AWeapon::setDamage(int damage){this->damage_ = damage;}

void AWeapon::showStatus() const
{
	std::cout.setf(std::ios::left);
	std::cout << "AWeapon " << std::endl;
	std::cout << std::setw(10) << "name : " << name_ << std::endl;
	std::cout << std::setw(10) << "apcost : " << apcost_ << std::endl;
	std::cout << std::setw(10) << "damage : " << damage_ << std::endl;
}
