#include "Weapon.hpp"

class HumanB : public Weapon
{
	private :
		string _name;
	public:
		HumanB(string name = "noname", string weapon = "hand");
		~HumanB();
		string getName();
		void setName(string name);
		void attack();
};
