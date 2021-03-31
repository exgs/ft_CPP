#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
    public:
		Weapon();
		Weapon(std::string type);
		Weapon(const Weapon&);
		virtual ~Weapon();
		Weapon &operator=(const Weapon& op);

		const	std::string& getType(); // 값을 바뀔 수 있잖아..
		void	setType(const std::string& type);

	private:
		std::string _type;
};
#endif
