#include "ScavTrap.hpp"
#include <unistd.h>

int main()
{
	srand(time(NULL));
	std::cout << "=-=-=-=-=-=-=-=-=-=- start game =-=-=-=-=-=-=-=-=-=-" << std::endl;
	std::cout << "생성자, 복사생성자, =연산자 그리고 소멸자" << std::endl;
	ScavTrap yunslee("yunslee");
	ScavTrap jikang_temp("jikang");
	ScavTrap ykoh_temp("ykoh"); 
	ScavTrap jikang(jikang_temp);
	ScavTrap ykoh;
	ykoh = ykoh_temp; 
	// player 3명 ykoh, jikang, yunslee
	std::cout.setf(std::ios::left);
	jikang.show_status();

	jikang.takeDamage(yunslee.rangedAttack("jikang"));
	jikang.show_status();
	jikang.takeDamage(yunslee.rangedAttack("jikang"));
	jikang.show_status();
	//수리
	jikang.beRepaired(10);
	jikang.show_status();
	jikang.beRepaired(10);
	jikang.show_status();
	jikang.beRepaired(10);
	jikang.show_status();
	jikang.beRepaired(10);
	jikang.show_status();

	// 공격받음
	jikang.takeDamage(yunslee.meleeAttack("jikang"));
	jikang.show_status();
	jikang.takeDamage(yunslee.meleeAttack("jikang"));
	jikang.show_status();
	jikang.takeDamage(yunslee.meleeAttack("jikang")); // yunslee isn't able to do melee Attack
	jikang.show_status();
	jikang.takeDamage(ykoh.meleeAttack("jikang"));
	jikang.show_status(); // 여기서 죽음
	jikang.takeDamage(ykoh.meleeAttack("jikang"));
	jikang.show_status(); // 이미 죽음

	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;

	yunslee.beRepaired(2000);
	yunslee.show_status();
	yunslee.beRepaired(-220); // 사실상 프로그래머가 하면 안되는 행동이지 않을까?
	yunslee.show_status();
	yunslee.charge_fullEP();
	yunslee.beRepaired((int)-1-100);// 사실상 프로그래머가 하면 안되는 행동이지 않을까?
	//prototype으로 자료형을 제시했는데, 일부러 형을 맞춰서 주지 않는다는 건
	
	//challengeNewcomer
	for (size_t i = 0; i < 5; i++)
	{
		yunslee.charge_fullEP();
		yunslee.challengeNewcomer();
		yunslee.challengeNewcomer();
		yunslee.charge_fullEP();
		yunslee.challengeNewcomer();
		yunslee.challengeNewcomer();
		sleep(1);
	}
	std::cout << "=-=-=-=-=-=-=-=-=-=- end game =-=-=-=-=-=-=-=-=-=-" << std::endl;
	return (0);
}
