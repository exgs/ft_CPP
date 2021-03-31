#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"


# include <iostream>
# include <iomanip>
# include <string>
# include <sys/time.h>
# include <ctime>

// using namespace std;

class NinjaTrap : public ClapTrap
{
	public:
		NinjaTrap(std::string name = "");
		NinjaTrap(const NinjaTrap &ref);
		~NinjaTrap();
		NinjaTrap& operator=(const NinjaTrap &ref);

		void   ninjaShoebox(FragTrap &ref);
		void   ninjaShoebox(ScavTrap &ref);
		void   ninjaShoebox(NinjaTrap &ref);
		void   ninjaShoebox(ClapTrap &ref);
};


#endif
