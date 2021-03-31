#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh..." << std::endl;
}

TacticalMarine::TacticalMarine(const TacticalMarine &)
{
	// (TacticalMarine)ref; // error가 발생함...
	// std::cout << "Tactical Marine ready for battle!" << std::endl; // 문제에서 원하지 않는 것
}

TacticalMarine &TacticalMarine::operator=(const TacticalMarine &ref)
{
	if (this == &ref)
		return (*this);
	// (TacticalMarine)ref;
	return (*this);
}

// 순수가상함수 받아서 정의하자
ISpaceMarine* TacticalMarine::clone() const
{
	ISpaceMarine* temp = new TacticalMarine((TacticalMarine &)*this);
	return (temp);
}

void TacticalMarine::battleCry() const
{
	std::cout << "For the holy PLOT!" << std::endl;
}

void TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with a bolter *" << std::endl;
}


void TacticalMarine::meleeAttack() const
{
	std::cout << "* attacks with a chainsword *" << std::endl;
}

