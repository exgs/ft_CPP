#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
// using namespace std;

class Zombie
{
	public:
		std::string _name;
		std::string _type;
	public:
		Zombie(std::string = "no_type", std::string = "null");
		~Zombie(); //heap이면 소멸시에 delete
		Zombie &operator=(const Zombie& op);
		void settype(std::string type);
		void setname(std::string name);
		std::string gettype();
		std::string getname();
		void announce();
};
#endif
