#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <sys/time.h>
# include <ctime>

// using namespace std;

typedef enum
{
	NONE = 0,
	VAULTHUNTER_DOT_EXE = 25,
	CHALLENGE_NEWCOMER = 25
}		consumer_ep;

class FragTrap
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
		FragTrap(std::string name = "");
		FragTrap(const FragTrap &ref);
		~FragTrap();
		FragTrap& operator=(const FragTrap &ref);

		unsigned int 	rangedAttack(std::string const & target);
		unsigned int 	meleeAttack(std::string const & target);
		void			beRepaired(unsigned int amount);
		void			takeDamage(unsigned int amount);
		unsigned int	vaulthunter_dot_exe(std::string const &target);

		/* 서브젝트 외적으로 내가 구현한 함수 */
		bool 			is_alive();
		bool 			is_able_do_something(std::string const &do_something, consumer_ep value); // 임시변수값을 받기 위해서 const를 설정함

		void			show_status();
		void			charge_fullEP();
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
