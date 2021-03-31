#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
	public:
		TacticalMarine();
		virtual ~TacticalMarine();
		TacticalMarine(const TacticalMarine &ref);
		TacticalMarine &operator=(const TacticalMarine &ref);

		// 순수가상함수 받아서 정의하자
		ISpaceMarine* clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;
};

# endif
