#ifndef SORCERER_HPP
# define SORCERER_HPP

#include "Victim.hpp"
# include <iostream>
# include <string>

// using namespace std;

class Sorcerer
{
	private:
		std::string name_;
		std::string title_;
		Sorcerer();

	public:
		Sorcerer(std::string name, std::string title);
		Sorcerer(const Sorcerer &ref);
		virtual ~Sorcerer();
		Sorcerer &operator=(const Sorcerer &ref);
		std::string getName() const;
		std::string getTitle() const;
		void polymorph(Victim const &ref);
};

std::ostream &operator<<(std::ostream &os, const Sorcerer &ref); //여기서 값을 이용할 수 있게 get함수 만들자.
#endif
