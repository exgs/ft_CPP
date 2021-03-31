#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include "Enemy.hpp"

class RadScorpion : public Enemy
{
	public:
		RadScorpion();
		RadScorpion(const RadScorpion &ref);
		virtual ~RadScorpion();
		RadScorpion& operator=(const RadScorpion &ref);

		void takeDamage(int damage);
};

# endif
