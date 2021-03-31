#include "ClapTrap.hpp"

/* 할당 */
// ClapTrap::ClapTrap(std::string name)
// {
// 	this->_hit_points = 1;
// 	this->_max_hit_points = 1;
// 	this->_energy_points = 1;
// 	this->_max_energy_points = 1;
// 	this->_level = 1;
// 	this->_name = name;
// 	this->_melee_attack_damage = 1;
// 	this->_ranged_attack_damage = 1;
// 	this->_armor_damage_reduction = 1;
// 	std::cout << "[ClapTrap] : " << "<" <<_name << ">" << "생성!" << std::endl;
// }

/* 초기화 리스트 */
ClapTrap::ClapTrap(std::string name) :
	_hit_points(1),
	_max_hit_points(1),
	_energy_points(1),
	_max_energy_points(1),
	_level(1),
	_melee_attack_damage(1),
	_ranged_attack_damage(1),
	_armor_damage_reduction(1),
	_name(name)
{
	std::cout << "[ClapTrap] : " << "<" << _name << ">" << "생성!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ref)
{
	_hit_points = ref._hit_points;
	_max_hit_points = ref._max_hit_points;
	_energy_points = ref._energy_points;
	_max_energy_points = ref._max_energy_points;
	_level = ref._level;
	_melee_attack_damage = ref._melee_attack_damage;
	_ranged_attack_damage = ref._ranged_attack_damage;
	_armor_damage_reduction = ref._armor_damage_reduction;
	_name = ref._name;
	std::cout << "[ClapTrap] : " << "<" << _name << ">" << "복사!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap] : " << "<" << _name << ">" << "소멸!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &ref)
{
	_hit_points = ref._hit_points;
	_max_hit_points = ref._max_hit_points;
	_energy_points = ref._energy_points;
	_max_energy_points = ref._max_energy_points;
	_level = ref._level;
	_name = ref._name;
	_melee_attack_damage = ref._melee_attack_damage;
	_ranged_attack_damage = ref._ranged_attack_damage;
	_armor_damage_reduction = ref._armor_damage_reduction;
	std::cout << "[ClapTrap] : " << "<" << _name << ">" << "대입!" << std::endl;
	return (*this);
}


// 함수 설정
bool ClapTrap::is_alive()
{
	if (this->_hit_points <= 0)
	{
		_hit_points = 0;
		return (false);
	}
	else
		return (true);
}

bool ClapTrap::is_able_do_something(std::string const &do_something, consumer_ep value)
{
	if (is_alive() == false)
	{
		std::cout << _name << " isn't able to do " << do_something << " because he died" << std::endl;
		return (false);
	}
	else if (value != NONE && _energy_points < value)
	{
		std::cout << _name << " isn't able to do " << do_something << " because not energy points" << std::endl;
		return (false);
	}
	else if (value != NONE)
		_energy_points -= 25;
	else
		return (true);
	return (true);
}

void ClapTrap::show_status()
{
	std::string line = "----------------------------------------------------";
	std::string temp;
	size_t word_size = 5;
	size_t line_size = 37;
	std::cout << std::endl;
	std::cout << _name ;
	temp = line.substr(0, line_size - _name.size());
	std::cout << temp << std::endl;
	std::cout << "|HP : "    << std::setw(word_size)	<< _hit_points << "|";
	std::cout << "EP : "    << std::setw(word_size)	<< _energy_points << "|";
	std::cout << "Level : " << std::setw(word_size)	<< _level << "|";
	std::cout << std::endl;
	temp = line.substr(0, line_size);
	std::cout << temp << std::endl;
	std::cout << std::endl;
}

unsigned int ClapTrap::rangedAttack(std::string const &target)
{
	std::cout <<"[range Attack]" << std::endl;
	if (is_able_do_something((std::string)"range Attack", NONE) == false)
		return (0);
	unsigned int damage;
	damage = _ranged_attack_damage;
	std::cout << "FR4G-TP " << _name << " attacks " << target << " at range, causing " << damage << " points of damage!" << std::endl;
	return (damage);
}

unsigned int ClapTrap::meleeAttack(std::string const & target)
{
	std::cout <<"[melee Attack]" << std::endl;
	if (is_able_do_something((std::string)"melee Attack", NONE) == false)
		return (0);
	unsigned int damage;
	damage = _melee_attack_damage;
	std::cout << "FR4G-TP " << _name << " attacks " << target << " at range, causing " << damage << " points of damage!" << std::endl;
	return (damage);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	// cout << "amount(unsigned):" << amount << std::endl;
	std::cout <<"[be Repaired]" << " : " << _name << std::endl;
	if (is_able_do_something((std::string)"be Reparied", NONE) == false)
		return ;
	std::cout << "HP : " << _hit_points;
	std::cout << " -> ";
	double temp;
	temp = amount + _hit_points;
	if (temp > _max_energy_points)
		_hit_points = _max_hit_points;
	else
		_hit_points+= amount;
	std::cout << "HP : " << _hit_points << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout <<"[take Damage]" << std::endl;
	if (is_alive() == false)
	{
		std::cout << _name << " is already died" << std::endl;
		return ;
	}
	unsigned int real_damage;
	if (amount < _armor_damage_reduction)
		real_damage = 0;
	else
		real_damage = amount - _armor_damage_reduction;
	_hit_points -= real_damage;
	std::cout << _name << " is damaged. -" << real_damage << std::endl;
	if (is_alive() == false)
		std::cout << _name << " is died now" << std::endl;
	return ;
}

void	ClapTrap::charge_fullEP()
{
	std::cout << "[charge_fullEp]" << " : " << _name << std::endl;
	_energy_points = _max_energy_points;
}
