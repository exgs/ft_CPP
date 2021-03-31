#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include "Zombie.hpp"
# include <ctime>
#include <sys/time.h>

// using namespace std;

class Zombieevent
{
	private:
		std::string _type;
	public:
		Zombieevent();
		Zombieevent(const Zombieevent&);
		virtual ~Zombieevent();
		void operator=(const Zombieevent &op);
		void setZombieType(std::string type);
		std::string getZombieType();
		
		Zombie *newZombie(std::string name);
		//Zombie &newZombie2(std::string name); // <- 동적할당하고선, 반환형을 레퍼런스로 하는 것은 좋지 않다. it's evil
		Zombie *randomChump();
		void announce_type();
};
#endif
