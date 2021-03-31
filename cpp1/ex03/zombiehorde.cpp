#include "ZombieHorde.hpp"
#include <ctime>

ZombieHorde::ZombieHorde(int n)
{
	if (n <= 0)
	{
		std::cout << "좀비 수가 적절하지 않습니다." << std::endl;
		std::cout << "좀비 수를 지정값 1로 설정합니다." << std::endl;
		n = 1;
	}
	this->_zombies = new Zombie[n];
	// you must allocate all the Zombie objects in a signle allocation.
	this->_n = n;
	srand(time(NULL));
	std::string array[26] = {"apple", "boy", "candy", "dude", "elegant", "fog"
						,"graph", "holy", "ill", "july", "kaggle"
							,"lemon", "monkey", "net", "orange", "peddle"
								,"queen", "rabbit", "star", "tow", "ulgy",
									"violet", "wow", "xai", "yellow", "zoo"};
	for (int i = 0; i < n; i++)
	{
		int random;
		random = rand() % 26;
		this->_zombies[i].setname(array[random]);
	}
}

ZombieHorde::ZombieHorde(const ZombieHorde& copy)
:
    _zombies(copy._zombies),
    _n(copy._n)
{}

ZombieHorde::~ZombieHorde() {delete [] _zombies;}

ZombieHorde &ZombieHorde::operator=(const ZombieHorde& obj)
{
	if (this == &obj)
		return (*this);
	this->_n = obj._n;
	this->_zombies = obj._zombies;
	return (*this);
}

void ZombieHorde::announce()
{
	std::cout << "------------" << this->_n << "------------" << std::endl;
    int z_count = 0;
    while(z_count < this->_n)
    {
        _zombies[z_count].announce();
        z_count++;
    }
	std::cout << "------------end------------" << std::endl;
}
