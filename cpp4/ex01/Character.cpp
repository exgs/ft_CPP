#include "Character.hpp"

Character::Character() :
	name_("null"), ap_(40), weapon_(NULL)
{
	// std::cout << "character created" << std::endl;
}

Character::Character(std::string const &name)
{
	name_ = name;
	ap_ = 40;
	weapon_ = NULL;
	// std::cout << "character created" << std::endl;
}

Character::Character(const Character &ref) :
	name_(ref.name_), ap_(ref.ap_), weapon_(ref.weapon_)
{
	// std::cout << "character created" << std::endl;
}

Character::~Character()
{
	// std::cout << "Character destroyed" << std::endl;
}

Character	&Character::operator=(const Character &ref)
{
	if (this == &ref)
		return (*this);
	name_ = ref.name_;
	ap_ = ref.ap_;
	weapon_ = ref.weapon_;
	std::cout << "character assignation" << std::endl;
	return (*this);
}

void	Character::recoverAP()
{
	std::cout << "ap is [" << ap_ << "] -> ";
	if (ap_ >= 40)
	{
		std::cout << ap_ << std::endl;
		return ;
	}
	ap_ += 10;
	if (ap_ >= 40)
		ap_ = 40;
	std::cout << ap_ << std::endl;
	return ;
}

void	Character::equip(AWeapon *weapon){this->weapon_ = weapon;}

void	Character::attack(Enemy *enemy)
{
	if (weapon_ == NULL)
	{
		std::cout << this->getName() << " can't attack" << enemy->getType() << "because unarmed" << std::endl;
		return ;
	}
	ap_ -= this->weapon_->getAPCost();
	if (ap_ < 0)
	{
		std::cout << "[attack] not enough ap" << std::endl;
		ap_ = 0;
		return ;
	}
	else
	{
		std::cout << name_ << " attacks " << enemy->getType() << " with a "<< weapon_->getName() <<'\n';
		weapon_->attack();
		enemy->takeDamage(this->weapon_->getDamage());
		if (enemy->getHP() <= 0)
			delete enemy;
	}
}

const std::string Character::getName() const{return (name_);}

int	Character::getAP() const{return (ap_);}

AWeapon	*Character::getWeapon() const{return (weapon_);	}

std::ostream &operator<<(std::ostream &os, const Character &ref)
{
	if (ref.getWeapon() == NULL)
		std::cout << ref.getName() << " has " << ref.getAP() << " AP and is unarmed" << std::endl;
	else
		std::cout << ref.getName() << " has " << ref.getAP() << " AP and wields a " << ref.getWeapon()->getName() << std::endl;
	return (os);
}
