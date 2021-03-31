# include "AWeapon.hpp"
# include "Enemy.hpp"
# include "PlasmaRifle.hpp"
# include "PowerFist.hpp"
# include "RadScorpion.hpp"
# include "SuperMutant.hpp"
# include "Character.hpp"

int main()
{
	Character* me = new Character("me");
	std::cout << *me;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	me->equip(pr);
	std::cout << *me;
	me->equip(pf);
	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	return 0;

	//
	// std::cout << "--------- start ---------" << std::endl;
	// Character yunslee("yunslee");
	// std::cout << yunslee;
	// // Enemy a("temp"); // 기본생성자가 private 멤버이기때문에 호출 불가능!
	// PowerFist weapon1;
	// PlasmaRifle weapon2;

	// // 적 만들기
	// Enemy *enemy1 = new SuperMutant;
	// Enemy *enemy2 = new RadScorpion;
	// yunslee.attack(enemy1); //무기가 없는경우
	// std::cout << yunslee; // 상태확인

	// yunslee.equip(&weapon1); //무기1 껴서 공격
	// yunslee.attack(enemy1);
	// std::cout << yunslee;

	// yunslee.equip(&weapon2); //무기2 껴서 공격
	// yunslee.attack(enemy2);
	// std::cout << yunslee;

	// yunslee.attack(enemy1);
	// yunslee.attack(enemy1);
	// yunslee.attack(enemy1);
	// yunslee.attack(enemy1);
	// yunslee.attack(enemy1);
	// yunslee.attack(enemy2);
	// yunslee.attack(enemy1);
	// yunslee.attack(enemy1);

	// yunslee.recoverAP(); // AP 회복
	// std::cout << yunslee;


	// std::cout << "--------- end ---------" << std::endl;
	// return 0;
}
