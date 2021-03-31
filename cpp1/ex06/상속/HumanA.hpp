#include "Weapon.hpp"

class HumanA : public Weapon
{
	private :
		string _name;
	public:
		HumanA(string name = "noname", string weapon = "hand");
		~HumanA();
		string getName();
		void setName(string name);
		void attack();
};
