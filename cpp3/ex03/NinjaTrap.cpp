#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name) // 진정한 overload!
{
	_hit_points = 60;
	_max_hit_points = 60;
	_energy_points = 120;
	_max_energy_points = 120;
	_level = 1;
	_melee_attack_damage = 60;
	_ranged_attack_damage = 5;
	_armor_damage_reduction = 0;
	_name = name;
	std::cout << "[NinjaTrap] : " << "<" << name << ">" << "생성!" << std::endl;
}

//복사 생성자를 명시적으로 만들어주었다면, 깊은 복사(deep copy)를 해야한다고 봄.
NinjaTrap::NinjaTrap(const NinjaTrap &ref) : ClapTrap(ref)
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
	std::cout << "[NinjaTrap] : " << "<" << ref._name << ">" << " 복사!" << std::endl;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "[NinjaTrap] : " << "<" << _name << ">" << "소멸!" << std::endl;
}

NinjaTrap& NinjaTrap::operator=(const NinjaTrap &ref)
{
	ClapTrap::operator=(ref);
	std::cout << "[NinjaTrap] : " << "<" << ref._name << ">"<< "대입!" << std::endl;
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

void	NinjaTrap::ninjaShoebox(FragTrap &ref)
{
	std::cout << "[ninjaShoebox] NinjaTrap is breaking FragTrap's Armor!" << std::endl;
	std::cout << "[FragTrap] : " << ref._name << " Armor : ";
	std::cout << ref.gettArmor() << " -> ";
	ref.setArmor(ref.gettArmor() - 2);
	std::cout << ref.gettArmor() << std::endl;
}

void	NinjaTrap::ninjaShoebox(ScavTrap &ref)
{
	std::cout << "[ninjaShoebox] NinjaTrap is breaking ScavTrap's Armor!" << std::endl;
	std::cout << "[ScavTrap] : " << ref._name << " Armor : ";
	std::cout << ref.gettArmor() << " -> ";
	ref.setArmor(ref.gettArmor() - 4);
	std::cout << ref.gettArmor() << std::endl;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap &ref)
{
	std::cout << "[ninjaShoebox] NinjaTrap is reinforcing his Armor by NinjaTrap!" << std::endl;
	std::cout << "[NinjaTrap] : " << ref._name << " Armor : ";
	std::cout << this->gettArmor() << " -> ";
	ref.setArmor(this->gettArmor() + 2);
	std::cout << ref.gettArmor() << std::endl;
}

void	NinjaTrap::ninjaShoebox(ClapTrap &ref)
{
	std::cout << "[ninjaShoebox] NinjaTrap is reinforcing his Armor by ClapTrap!" << std::endl;
	std::cout << "[NinjaTrap] : " << ref._name << " Armor : ";
	std::cout << this->gettArmor() << " -> ";
	ref.setArmor(this->gettArmor() + 4);
	std::cout << ref.gettArmor() << std::endl;
}
