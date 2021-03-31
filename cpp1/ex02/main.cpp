// #include "Zombie.hpp"
#include <iostream>
#include "ZombieEvent.hpp"

// using namespace std;
int main()
{
	std::cout << std::endl << "======STEP1_zombie_class======" << std::endl << std::endl;
	Zombie a("A", "zombie_a"); a.announce();
	Zombie b; b.announce();
	Zombie c("A"); c.announce();
	a.setname("yunslee"); a.settype("B"); a.announce();
	std::cout << "getname()함수로 name 가져오기 : " << a.getname() << std::endl;

	/*
	// b.setname(NULL);// -> it can't be possible for string class
	// b.setname("");// -> it can be possible for string class
	*/
	std::cout << "----------------------------------------------" << std::endl;
	a.setname("zombie_a"); a.announce();
	b.setname("zombie_b"); b.announce();
	c.setname("zombie_c"); c.announce();

	std::cout << std::endl << "======STEP2_zombieevent_class======" << std::endl << std::endl;
	Zombieevent ra1;
	ra1.announce_type();
	std::cout << "_type:? 에서  _type:AB 로 변경." << std::endl;
	ra1.setZombieType("AB");
	ra1.announce_type();
	std::cout << "복사 생성자 이용해본다." << std::endl;
	Zombieevent ra2(ra1);
	ra2.announce_type();

	Zombie *temp;
	temp = ra2.newZombie("pointer");
	temp->announce();
	// delete temp;

	temp = NULL;
	ra1.setZombieType("O");
	temp = ra1.newZombie("who..am..i?");
	temp->announce();
	delete temp;
	temp = NULL;
	// /*메모리누수가 안난다..? -> 함수내부에서 호출한 경우 leaks가 발견하지 못하는 거 같음*/ -> 

	std::cout << std::endl << "======STEP3_random Zombie======" << std::endl << std::endl;
	Zombieevent new1(ra1);
	Zombie *new1_ptr;
	Zombieevent new2(ra2);
	Zombie *new2_ptr;
	new1_ptr =new1.randomChump();
	delete new1_ptr;
	new2_ptr =new2.randomChump();
	delete new2_ptr;
	std::cout << "----------------" << std::endl << std::endl;
	new1.setZombieType("unique");
	new1_ptr = new1.randomChump();
	new1_ptr->announce();
	delete new1_ptr;
	new2_ptr = new2.newZombie("two");
	new2_ptr->announce();
	delete new2_ptr;
	std::cout << "----------------" << std::endl;
	temp =new2.randomChump();
	delete temp;
	temp =new2.randomChump();
	delete temp;
	temp =new2.randomChump();
	delete temp;
	temp =new2.randomChump();
	delete temp;
	temp =new2.randomChump();
	delete temp;

	std::cout << "===================================" << std::endl;
	system("leaks a.out | grep leaks | grep Process");
	return (1);
}
