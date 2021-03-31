#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>
using namespace std;
class Weapon
{
	private :
		string _type;
	public:
		Weapon(string weapon = "hand");
		~Weapon();
		string getType();
		void setType(string weapon);
};
#endif