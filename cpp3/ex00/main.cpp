#include "FragTrap.hpp"


int main()
{
	srand(time(NULL));
	std::cout << "=-=-=-=-=-=-=-=-=-=- start game =-=-=-=-=-=-=-=-=-=-" << std::endl;
	std::cout << "생성자, 복사생성자, =연산자 그리고 소멸자" << std::endl;
	FragTrap yunslee("yunslee");
	FragTrap jikang_temp("jikang");
	FragTrap ykoh_temp("ykoh"); 
	FragTrap jikang(jikang_temp);
	FragTrap ykoh;
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
	
	//vaulthunter_dot_exe
	jikang_temp.show_status();
	jikang_temp.takeDamage(jikang_temp.vaulthunter_dot_exe("jikang_temp")); //자학하기
	jikang_temp.show_status(); //실행할 때 마다 달라짐.

	jikang_temp.vaulthunter_dot_exe("jikang_temp");
	jikang_temp.vaulthunter_dot_exe("jikang_temp");
	jikang_temp.charge_fullEP();
	jikang_temp.vaulthunter_dot_exe("jikang_temp");
	jikang_temp.charge_fullEP();
	jikang_temp.vaulthunter_dot_exe("jikang_temp");
	jikang_temp.charge_fullEP();
	jikang_temp.vaulthunter_dot_exe("jikang_temp");
	jikang_temp.vaulthunter_dot_exe("jikang_temp");

	std::cout << "=-=-=-=-=-=-=-=-=-=- end game =-=-=-=-=-=-=-=-=-=-" << std::endl;
	return (0);
}
