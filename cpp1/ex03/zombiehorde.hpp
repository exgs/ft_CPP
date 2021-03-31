#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include "Zombie.hpp"

class ZombieHorde
{
	public:
		// ZombieHorde();
		ZombieHorde(int n = 1);
		ZombieHorde(const ZombieHorde &);
		virtual ~ZombieHorde();
		ZombieHorde &operator=(const ZombieHorde &);
		void announce(); // 상속 받지 않았기 때문에 overriding한 것은 아니지만, 새로 짬
	private:
		Zombie *_zombies; // 좀비무리(Horde)를 담을 포인터
		int _n;
};

#endif
