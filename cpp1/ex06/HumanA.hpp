#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon& weapon);
		HumanA(const HumanA&);
		virtual ~HumanA();
		HumanA &operator=(const HumanA& op);
		void	setWeapon(Weapon& weapon);
		void attack();
	
	private:
	    std::string _name;
	    Weapon&     _weapon;
};

#endif
