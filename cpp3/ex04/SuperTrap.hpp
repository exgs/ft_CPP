#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include "NinjaTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>
# include <iomanip>
# include <string>
# include <sys/time.h>
# include <ctime>

// using namespace std;

class SuperTrap : public FragTrap, public NinjaTrap
// class SuperTrap : virtual public FragTrap, virtual public NinjaTrap
{
	public:
		SuperTrap(std::string name = "");
		SuperTrap(const SuperTrap &ref);
		~SuperTrap();
		SuperTrap& operator=(const SuperTrap &ref);

		unsigned int	rangedAttack(std::string const &target); //함수의 상속을 어떻게 규정하지? rangesAttack(Fragtrap)
		unsigned int	meleeAttack(std::string const &target); //함수의 상속을 어떻게 규정하지? rangesAttack(Fragtrap)
		void			show_status_all();
};

#endif
