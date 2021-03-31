// 상속받는 클래스들이 include 해야함.
#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>
// using namespace std;

class Enemy
{
	private :
		int			hp_;
		std::string	type_;
		Enemy();
	public:
		Enemy(int hp, std::string const &type);
		Enemy(const Enemy &ref);
		virtual ~Enemy();
		Enemy	&operator=(const Enemy &ref);

		std::string		getType() const;
		int				getHP() const;
		void			setType(std::string type);
		void			setHP(int hp);
		virtual void	takeDamage(int damage); // 가상함수(o), 순수가상함수(x)
};
#endif
