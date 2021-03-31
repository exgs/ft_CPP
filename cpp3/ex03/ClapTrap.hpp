#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP


# include <iostream>
# include <iomanip>
# include <string>
# include <sys/time.h>
# include <ctime>

# define MINUS 1073741824 // 음수를 넣어준 경우
// using namespace std;

typedef enum
{
	NONE = 0,
	VAULTHUNTER_DOT_EXE = 25,
	CHALLENGE_NEWCOMER = 25
}		consumer_ep;

class ClapTrap
{
	protected:
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
		ClapTrap(std::string name = "");
		ClapTrap(const ClapTrap &ref);
		~ClapTrap();
		ClapTrap& operator=(const ClapTrap &ref);

		unsigned int 	rangedAttack(std::string const & target);
		unsigned int 	meleeAttack(std::string const & target);
		void			beRepaired(unsigned int amount);
		void			takeDamage(unsigned int amount);
		/* 서브젝트 외적으로 내가 구현한 함수 */
		bool 			is_alive();
		bool 			is_able_do_something(std::string const &do_something, consumer_ep value); // 임시변수값을 받기 위해서 const를 설정함
		void			show_status();
		void			charge_fullEP();
		/* ex03에서 추가해준 함수 */
		void			setArmor(unsigned int value);
		unsigned int	gettArmor();
};

#endif
