#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <iomanip>
# include <string>
# include <sys/time.h>
# include <ctime>

// using namespace std;

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string name = "");
		ScavTrap(const ScavTrap &ref);
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap &ref);

		// unsigned int	vaulthunter_dot_exe(std::string const &target);
		unsigned int	 challengeNewcomer();

};


// const string g_name[5] = {"laser", "rock", "sacks", "iphone", "paper"};
// const unsigned int g_damage[5] = {20, 30, 40, 50, 10};


#endif
