#ifndef ISPACEMARINE_HPP
# define ISPACEMARINE_HPP

#include <iostream>
// using namespace std;

class ISpaceMarine
{
	public:
		virtual ~ISpaceMarine(){} // ISpaceMarine 포인터로 자식클래스 받는 경우 필요함.
		virtual ISpaceMarine* clone() const = 0;
		virtual void battleCry() const = 0;
		virtual void rangedAttack() const = 0;
		virtual void meleeAttack() const = 0;
};

#endif
