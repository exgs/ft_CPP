#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name) : ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
	// std::cout << "----------------< start >----------------" << std::endl;
	// ClapTrap(
    //     100, //FragTrap
    //     100, //FragTrap
    //     120, //NinjaTrap
    //     120, //NinjaTrap
    //     1,
    //     60, //NinjaTrap
    //     20, //FragTrap
    //     5, //FragTrap
    //     name
    // );
	/* 위에서처럼 생성자를 호출시키면, 해당 생성자가 독립적으로 생성되었다가 소멸될 뿐 main문에서 정의된 객체에 영향을 주지 못한다.*/
	this->_hit_points = 100;
	this->_max_hit_points = 100;
	this->_energy_points = 120;
	this->_max_energy_points = 120;
	this->_level = 1;
	this->_melee_attack_damage = 60;
	this->_ranged_attack_damage = 20;
	this->_armor_damage_reduction = 5;
	this->_name = name;
	std::cout << "[SuperTrap] : " << "<" << name << ">" << "생성!" << std::endl;
	// std::cout << "----------------< end >----------------" << std::endl;
}

//복사 생성자를 명시적으로 만들어주었다면, 깊은 복사(deep copy)를 해야한다고 봄.
SuperTrap::SuperTrap(const SuperTrap &ref) : ClapTrap(ref), FragTrap(ref), NinjaTrap(ref) // 두개 모두 복사생성자를 ClapTrap에서 받아쓰고 있음.
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
	std::cout << "[SuperTrap] : " << "<" << ref._name << ">" << " 복사!" << std::endl;
}

SuperTrap::~SuperTrap()
{
	std::cout << "[SuperTrap] : " << "<" << _name << ">" << "소멸!" << std::endl;
}

SuperTrap& SuperTrap::operator=(const SuperTrap &ref)
{
	ClapTrap::operator=(ref);
	std::cout << "[SuperTrap] : " << "<" << ref._name << ">"<< "대입!" << std::endl;
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


// SuperTrap의 rangedAttack은 FragTrap의 rangedAttack를 사용
unsigned int	SuperTrap::rangedAttack(std::string const &target)
{
	return (FragTrap::rangedAttack(target));
}

// SuperTrap의 meleeAttack은 NinjaTrap의 meleeAttack를 사용
unsigned int    SuperTrap::meleeAttack(std::string const &target)
{
	return (NinjaTrap::meleeAttack(target));
}

void SuperTrap::show_status_all()
{
	std::cout << "====SuperTrap Data====\n" << std::endl;
	std::cout << this->_hit_points << std::endl;
	std::cout << this->_max_hit_points << std::endl;
	std::cout << this->_energy_points << std::endl;
	std::cout << this->_max_energy_points << std::endl;
	std::cout << this->_level << std::endl;
	std::cout << this->_melee_attack_damage << std::endl;
	std::cout << this->_ranged_attack_damage << std::endl;
	std::cout << this->_armor_damage_reduction << std::endl;
}
