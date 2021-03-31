#include "Enemy.hpp"

Enemy::Enemy()
: hp_(100), type_("null")
{}

Enemy::Enemy(int hp, std::string const &type)
: hp_(hp), type_(type)
{
	// std::cout << "Enemy created" << std::endl;
}

Enemy::Enemy(const Enemy &ref)
: hp_(ref.hp_), type_(ref.type_)
{
	// std::cout << "Enemy assignation" << std::endl;
}

Enemy::~Enemy()
{
	// std::cout << "Enemy destroyed" << std::endl;
}

Enemy	&Enemy::operator=(const Enemy &ref)
{
	if (this == &ref)
		return (*this);
	hp_ = ref.hp_;
	type_ = ref.type_;
	return (*this);
}

std::string		Enemy::getType() const{return (this->type_);}

int				Enemy::getHP() const{return (this->hp_);}

void			Enemy::setType(std::string type){this->type_ = type;}

void			Enemy::setHP(int hp){this->hp_ = hp;}

void	Enemy::takeDamage(int damage)
{
	if (hp_ <= 0)
	{
		// std::cout << "[takeDamage] enemy already died" << std::endl;
		return ;
	}
	if (damage < 0)
	{
		// std::cout << "[takeDamage] damage is zero" << std::endl;
		return ;
	}
	hp_ -= damage;
	// std::cout << "[takeDamage] damage is " << damage << std::endl;
	if (hp_ <= 0)
	{
		// std::cout << "[takeDamage] enemy is now died" << std::endl;
		hp_ = 0;
		return ;
	}
}
