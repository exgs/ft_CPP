#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
:
	_hit_points(100),
	_max_hit_points(100),
	_energy_points(100),
	_max_energy_points(100),
	_level(1),
	_melee_attack_damage(30),
	_ranged_attack_damage(20),
	_armor_damage_reduction(5),
	_name(name)
{
	// srand(time(NULL));
	std::cout << "[FragTrap] : " << "<" <<_name << ">" << "생성!" << std::endl;
}

//복사 생성자를 명시적으로 만들어주었다면, 깊은 복사(deep copy)를 해야한다고 봄.
FragTrap::FragTrap(const FragTrap &ref):
	_hit_points(ref._hit_points),
	_max_hit_points(ref._max_hit_points),
	_energy_points(ref._energy_points),
	_max_energy_points(ref._max_energy_points),
	_level(ref._level),
	_melee_attack_damage(ref._melee_attack_damage),
	_ranged_attack_damage(ref._ranged_attack_damage),
	_armor_damage_reduction(ref._armor_damage_reduction),
	_name(ref._name)
{
	// srand(time(NULL));
	std::cout << "[FragTrap] : " << "<" << ref._name << ">" << " 복사!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] : " << "<" << _name << ">" << "소멸!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &ref)
{
	std::cout << "[FragTrap] : " << "<" << ref._name << ">"<< "대입!" << std::endl;
	_hit_points = ref._hit_points;
	_max_hit_points = ref._max_hit_points;
	_energy_points = ref._energy_points;
	_max_energy_points = ref._max_energy_points;
	_level = ref._level;
	_name = ref._name;
	_melee_attack_damage = ref._melee_attack_damage;
	_ranged_attack_damage = ref._ranged_attack_damage;
	_armor_damage_reduction = ref._armor_damage_reduction;
	return (*this);
}

// 함수 설정
bool FragTrap::is_alive()
{
	if (this->_hit_points <= 0)
	{
		_hit_points = 0;
		return (false);
	}
	else
		return (true);
}

bool FragTrap::is_able_do_something(std::string const &do_something, consumer_ep value)
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

void FragTrap::show_status()
{
	std::string line = "----------------------------------------------------";
	std::string temp;
	size_t word_size = 5;
	size_t line_size = 35;
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

unsigned int FragTrap::rangedAttack(std::string const &target)
{
	if (is_able_do_something((std::string)"range Attack", NONE) == false)
		return (0);
	unsigned int damage;
	damage = _ranged_attack_damage;
	std::cout << "FR4G-TP " << _name << " attacks " << target << " at range, causing " << damage << " points of damage!" << std::endl;
	return (damage);
}

unsigned int FragTrap::meleeAttack(std::string const & target)
{
	if (is_able_do_something((std::string)"melee Attack", NONE) == false)
		return (0);
	unsigned int damage;
	damage = _melee_attack_damage;
	std::cout << "FR4G-TP " << _name << " attacks " << target << " at range, causing " << damage << " points of damage!" << std::endl;
	return (damage);
}

void FragTrap::beRepaired(unsigned int amount)
{
	// cout << "amount(unsigned):" << amount << std::endl;
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

void FragTrap::takeDamage(unsigned int amount)
{
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

unsigned int	FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	if (is_able_do_something("vaulthunter_dot_exe", VAULTHUNTER_DOT_EXE) == false)
		return (0);
	timeval time2;
	int random;
	random = rand() % 5;
	gettimeofday(&time2, NULL);
	random = time2.tv_usec % 5; // 랜덤성은 이걸로 충분하다고 봄
	unsigned int damage;
	std::string name;
	damage = g_damage[random];
	name = g_name[random];
	std::cout << "Weapon is " << name << std::endl;
	std::cout << "FR4G-TP " << _name << " attacks " << target << " at range, causing " << damage << " points of damage!" << std::endl;
	std::cout << std::endl;
	return (damage);
}

void	FragTrap::charge_fullEP()
{
	_energy_points = _max_energy_points;
}
