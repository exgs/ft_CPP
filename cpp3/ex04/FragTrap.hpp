#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <iomanip>
# include <string>
# include <sys/time.h>
# include <ctime>

// using namespace std;

class FragTrap : virtual public ClapTrap //처리 1
{
	public:
		FragTrap(std::string name = "");
		FragTrap(const FragTrap &ref);
		~FragTrap();
		FragTrap& operator=(const FragTrap &ref);

		
		unsigned int	vaulthunter_dot_exe(std::string const &target);
};


const std::string g_name[5] = {"laser", "rock", "sacks", "iphone", "paper"};
const unsigned int g_damage[5] = {20, 30, 40, 50, 10};
// 아래 형식은 c++11에서만 가능함
// Warning : in-class initialization of non-static data member is a C++11 extension [-Wc++11-extensions]
// typedef struct
// {
// 	const	string name[5] = {"laser", "rock", "sacks", "iphone", "paper"};
// 	const unsigned int damage[5] = {20, 30, 40, 50, 10};
// }	t_weapons;
// bool is_alive(FragTrap const &object) 함수를 어디다가 위치하게 할까>


#endif
