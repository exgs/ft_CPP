#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <unistd.h>

int main()
{
	srand(time(NULL));
	std::cout << "=-=-=-=-=-=-=-=-=-=- start game =-=-=-=-=-=-=-=-=-=-" << std::endl;
	ScavTrap yunslee("yunslee");
	ClapTrap jikang_temp("jikang");
	FragTrap ykoh("ykoh");
	ClapTrap jikang(jikang_temp);
	std::cout.setf(std::ios::left);
	ykoh.show_status();

	jikang.show_status();
	jikang.takeDamage(ykoh.rangedAttack("ykoh"));
	jikang.show_status();

	ykoh.takeDamage(yunslee.rangedAttack("ykoh"));
	ykoh.show_status();
	ykoh.takeDamage(yunslee.rangedAttack("ykoh"));
	ykoh.show_status();

	std::cout << "---------------- 수리 ----------------" << std::endl;
	//수리
	ykoh.beRepaired(10);
	ykoh.show_status();
	ykoh.beRepaired(300);
	ykoh.show_status();
	ykoh.beRepaired(20000);
	ykoh.show_status();

	// 공격받음
	ykoh.charge_fullEP();
	std::cout << "---------------- 공격 받음 ----------------" << std::endl;
	yunslee.takeDamage(ykoh.meleeAttack("yunslee"));
	yunslee.show_status();
	yunslee.takeDamage(ykoh.meleeAttack("yunslee"));
	yunslee.show_status();
	yunslee.takeDamage(ykoh.meleeAttack("yunslee")); // yunslee isn't able to do melee Attack
	yunslee.show_status();
	//충전
	ykoh.charge_fullEP();
	yunslee.charge_fullEP();
	yunslee.beRepaired(200);
	yunslee.show_status();
	//
	yunslee.takeDamage(ykoh.meleeAttack("yunslee"));
	yunslee.show_status();
	yunslee.takeDamage(ykoh.meleeAttack("yunslee"));
	yunslee.show_status();
	yunslee.takeDamage(ykoh.meleeAttack("yunslee"));
	yunslee.show_status();

	std::cout << "---------end--------" << std::endl;

	ykoh.beRepaired(2000);
	ykoh.show_status();
	ykoh.beRepaired(-220);
	ykoh.show_status();
	ykoh.charge_fullEP();
	ykoh.beRepaired((int)-1-100);// 사실상 프로그래머가 하면 안되는 행동이지 않을까?
	//prototype으로 자료형을 제시했는데, 일부러 형을 맞춰서 주지 않는다는 건
	ykoh.show_status();

	//challengeNewcomer
	std::cout << "=-=-=-=-=-=-=-=-=-=- challengeNewcomer =-=-=-=-=-=-=-=-=-=-" << std::endl;
	for (size_t i = 0; i < 5; i++)
	{
		yunslee.challengeNewcomer();
		yunslee.charge_fullEP();
		// sleep(1);
	}

	std::cout << "=-=-=-=-=-=-=-=-=-=- vaulthunter_dot_exe =-=-=-=-=-=-=-=-=-=-" << std::endl;
	//자학하기
	ykoh.takeDamage(ykoh.vaulthunter_dot_exe("jikang_temp"));
	ykoh.show_status();
	ykoh.takeDamage(ykoh.vaulthunter_dot_exe("jikang_temp"));
	ykoh.show_status();
	ykoh.takeDamage(ykoh.vaulthunter_dot_exe("jikang_temp"));
	ykoh.show_status();
	ykoh.takeDamage(ykoh.vaulthunter_dot_exe("jikang_temp"));
	ykoh.show_status();
	ykoh.takeDamage(ykoh.vaulthunter_dot_exe("jikang_temp"));
	ykoh.show_status();
	ykoh.charge_fullEP();
	ykoh.takeDamage(ykoh.vaulthunter_dot_exe("jikang_temp"));
	ykoh.show_status();
	std::cout << "=-=-=-=-=-=-=-=-=-=- end game =-=-=-=-=-=-=-=-=-=-" << std::endl;
	return (0);
}
