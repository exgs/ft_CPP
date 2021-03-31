#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) // 진정한 overload!
{
	this->_hit_points = 100;
	this->_max_hit_points = 100;
	this->_energy_points = 50;
	this->_max_energy_points = 50;
	this->_level = 1;
	this->_name = name;
	this->_melee_attack_damage = 20;
	this->_ranged_attack_damage = 15;
	this->_armor_damage_reduction = 3;
	// srand(time(NULL));
	std::cout << "[ScavTrap] : " << "<" << _name << ">" << "생성!" << std::endl;
}

//복사 생성자를 명시적으로 만들어주었다면, 깊은 복사(deep copy)를 해야한다고 봄.
ScavTrap::ScavTrap(const ScavTrap &ref) : ClapTrap(ref)
{
	// _hit_points(ref._hit_points),
	// _max_hit_points(ref._max_hit_points),
	// _energy_points(ref._energy_points),
	// _max_energy_points(ref._max_energy_points),
	// _level(ref._level),
	// _name(ref._name),
	// _melee_attack_damage(ref._melee_attack_damage),
	// _ranged_attack_damage(ref._ranged_attack_damage),
	// _armor_damage_reduction(ref._armor_damage_reduction)
	// srand(time(NULL));
	std::cout << "[ScavTrap] : " << "<" << _name << ">" << "복사!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] : " << "<" << _name << ">" << "소멸!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &ref)
{
	ClapTrap::operator=(ref);
	std::cout << "[ScavTrap] : " << "<" << _name << ">" << "대입!" << std::endl;
	// _hit_points = ref._hit_points;
	// _max_hit_points = ref._max_hit_points;
	// _energy_points = ref._energy_points;
	// _max_energy_points = ref._max_energy_points;
	// _level = ref._level;
	// _name = ref._name;
	// _melee_attack_damage = ref._melee_attack_damage;
	// _ranged_attack_damage = ref._ranged_attack_damage;
	// _armor_damage_reduction = ref._armor_damage_reduction;
	return (*this);
}

unsigned int	ScavTrap::challengeNewcomer()
{
	if (is_able_do_something("challengeNewcomer", CHALLENGE_NEWCOMER) == false)
		return (0);
	timeval time2;
	std::string pool[5] = {
		"\"Practice instruments!\"",
		"\"Do the right Thing!\"",
		"\"Don't be panic\"",
		"\"Smile everyday\"",
		"\"Drink water\""
	};
	int random;
	random = rand() % 5;
	gettimeofday(&time2, NULL);
	random = time2.tv_usec % 5;
	std::string name = pool[random];
	std::cout << _name << " : " << name << std::endl;
	return (1);
}
