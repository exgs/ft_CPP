#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
#include <unistd.h>

int main()
{
	srand(time(NULL));
	std::cout << "=-=-=-=-=-=-=-=-=-=- start game =-=-=-=-=-=-=-=-=-=-" << std::endl;


	SuperTrap yunslee("yunslee");
	SuperTrap jikang_temp("jikang");
	SuperTrap ykoh("ykoh");
	SuperTrap jikang(jikang_temp);
	std::cout.setf(std::ios::left);

	// ranaged Attack
	jikang.takeDamage(ykoh.rangedAttack("jikang")); // 20
	jikang.show_status();

	// melee Attack
	jikang.takeDamage(ykoh.meleeAttack("jikang")); // 60
	jikang.show_status();

	// it has the speical attacks of both its parents(NinajaTrap, FragTrap)
	jikang.vaulthunter_dot_exe("sdfs");
	NinjaTrap temp("temp");
	jikang.ninjaShoebox(temp);
	std::cout << "=-=-=-=-=-=-=-=-=-=- end game =-=-=-=-=-=-=-=-=-=-" << std::endl;
	return (0);
}
