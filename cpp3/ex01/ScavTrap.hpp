#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <sys/time.h>
# include <ctime>

typedef enum
{
	NONE = 0,
	VAULTHUNTER_DOT_EXE = 25,
	CHALLENGE_NEWCOMER = 25
}		consumer_ep;

// using namespace std;

class ScavTrap
{
	private:
		int _hit_points;
		unsigned int _max_hit_points;
		int _energy_points;
		unsigned int _max_energy_points;

		unsigned int _level;
		unsigned int _melee_attack_damage;
		unsigned int _ranged_attack_damage;
		unsigned int _armor_damage_reduction;
	public:
		std::string _name;
		ScavTrap(std::string name = "");
		ScavTrap(const ScavTrap &ref);
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap &ref);

		unsigned int 	rangedAttack(std::string const & target);
		unsigned int 	meleeAttack(std::string const & target);
		void			beRepaired(unsigned int amount);
		void			takeDamage(unsigned int amount);
		// unsigned int	vaulthunter_dot_exe(std::string const &target);
		unsigned int	 challengeNewcomer();

		/* 서브젝트 외적으로 내가 구현한 함수 */
		bool 			is_alive();
		bool 			is_able_do_something(std::string const &do_something, consumer_ep value); // 임시변수값을 받기 위해서 const를 설정함
		void			show_status();
		void			charge_fullEP();
};


// const string g_name[5] = {"laser", "rock", "sacks", "iphone", "paper"};
// const unsigned int g_damage[5] = {20, 30, 40, 50, 10};


#endif
