#include "ZombieEvent.hpp"
#include "Zombie.hpp"

Zombieevent::Zombieevent():
_type("?")
{}
Zombieevent::Zombieevent(const Zombieevent &zombieevnet):
	_type(zombieevnet._type)
{}

Zombieevent::~Zombieevent()
{
	std::cout << "<" << this->getZombieType() << "> ";
	std::cout << "Zombie event가 소멸자에 의해 죽었습니다." << std::endl ;
}

void Zombieevent::operator=(const Zombieevent & zombie)
{
	this->_type = zombie._type;
}

void Zombieevent::setZombieType(std::string type){this->_type = type;}
std::string Zombieevent::getZombieType(){return (this->_type);}

Zombie *Zombieevent::newZombie(std::string name)
{
	return (new Zombie(this->_type, name));
}

/* 반환형을 레퍼런스로 하는 것은 좋지 않다. it's evil
Zombie &Zombieevent::newZombieme2(std::string name)
{
	Zombie *temp = new Zombie(this->_type, name);
	return (*temp);
}
*/

Zombie *Zombieevent::randomChump()
{
	std::string array[5] = {"yunslee","jikang","ykoh","jinbkim","hjung"};
	std::string name;
	Zombie *temp;
	
	
	timeval clock;
	gettimeofday(&clock, NULL);
	int random;
	random = clock.tv_usec % 4 + 1;
	/* 모든 newZombie에서 "같은이름" 만 나옴.
	// srand(time(NULL));
	// random = rand() % 4 + 1;
	*/
	name = array[random];
	temp = newZombie(name);
	temp->announce();
	return temp;
	/* // 살아나자마자 죽는건 너무 슬프잖아(stack)
	Zombie temp2("O", name);
	temp2.announce();
	return ;
	*/
}

void Zombieevent::announce_type()
{
	std::cout << "Zombieevent _type : " << this->getZombieType() << std::endl;
}
