#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I'll be back..." << std::endl;
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator &)
{
	// (AssaultTerminator)ref; // error 발생
	// std::cout << "* teleports from space *" << std::endl; // 문제에서 원하지 않음
}

AssaultTerminator &AssaultTerminator::operator=(const AssaultTerminator &ref)
{
	if (this == &ref)
		return (*this);
	// (AssaultTerminator)ref;
	return (*this);
}

// 순수가상함수 받아서 정의하자
ISpaceMarine* AssaultTerminator::clone() const
{
	ISpaceMarine *temp = new AssaultTerminator((AssaultTerminator &)(*this));
	return (temp);
}

void AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;

}

void AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *" << std::endl;
}


void AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfists *" << std::endl;

}

