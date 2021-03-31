#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
private:
	std::string	name_;
	int			ap_;
	AWeapon		*weapon_; // upcasting으로 무기를 갈아끼우고 싶은거야

public:
	Character();
	Character(std::string const &name);
	Character(const Character &ref);
	~Character();
	Character	&operator=(const Character &ref);

	void        recoverAP();
	void        equip(AWeapon *weapon);
	void        attack(Enemy *enemy);
	const std::string getName() const;
	int         getAP() const;
	AWeapon     *getWeapon() const;
};

std::ostream &operator<<(std::ostream &os, const Character &ref);

#endif
