#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) // 진정한 overload!
{
	_hit_points = 100;
	_max_hit_points = 100;
	_energy_points = 100;
	_max_energy_points = 100;
	_level = 1;
	_melee_attack_damage = 30;
	_ranged_attack_damage = 20;
	_armor_damage_reduction = 5;
	// _name = name;
	// srand(time(NULL));
	std::cout << "[FragTrap] : " << "<" << _name << ">" << "생성!" << std::endl;
}

//복사 생성자를 명시적으로 만들어주었다면, 깊은 복사(deep copy)를 해야한다고 봄.
FragTrap::FragTrap(const FragTrap &ref) : ClapTrap(ref)
{
	// _hit_points = ref._hit_points;
	// _max_hit_points = ref._max_hit_points;
	// _energy_points = ref._energy_points;
	// _max_energy_points = ref._max_energy_points;
	// _level = ref._level;
	// _melee_attack_damage = ref._melee_attack_damage;
	// _ranged_attack_damage = ref._ranged_attack_damage;
	// _armor_damage_reduction = ref._armor_damage_reduction;
	// _name = ref._name;
	// srand(time(NULL));
	std::cout << "[FragTrap] : " << "<" << ref._name << ">" << " 복사!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] : " << "<" << _name << ">" << "소멸!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &ref)
{
	ClapTrap::operator=(ref);
	std::cout << "[FragTrap] : " << "<" << ref._name << ">"<< "대입!" << std::endl;
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

unsigned int	FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	if (is_able_do_something("vaulthunter_dot_exe", VAULTHUNTER_DOT_EXE) == false)
		return (0);
	timeval time2;
	int random;
	random = rand() % 5;
	gettimeofday(&time2, NULL);
	random = time2.tv_usec % 5;
	unsigned int damage;
	std::string name;
	damage = g_damage[random];
	name = g_name[random];
	std::cout << "Weapon is " << name << std::endl;
	std::cout << "FR4G-TP " << _name << " attacks " << target << " at range, causing " << damage << " points of damage!" << std::endl;
	std::cout << std::endl;
	return (damage);
}
