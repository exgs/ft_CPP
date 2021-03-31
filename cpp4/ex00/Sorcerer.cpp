#include "Sorcerer.hpp"

Sorcerer::Sorcerer() :
	name_("null"), title_("null")
{
	std::cout << name_ << ", " << title_ <<", is born!" << std::endl;
}

Sorcerer::Sorcerer(std::string name, std::string title):
	name_(name), title_(title)
{
	std::cout << name_ << ", " << title_ <<", is born!" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &ref) :
	name_(ref.name_), title_(ref.title_)
{
	std::cout << name_ << ", " << title_ <<", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
	std::cout << name_ << ", " << title_ << ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer &Sorcerer::operator=(const Sorcerer &ref)
{
	if (this == &ref)
		return (*this);
	name_ = ref.getName();
	title_ = ref.getTitle();
	return (*this);
}

std::string Sorcerer::getName() const{return (name_);}

std::string Sorcerer::getTitle() const{return (title_);}

std::ostream &operator<<(std::ostream &os, const Sorcerer &ref)
{
	std::cout << "I am " << ref.getName() << ", " << ref.getTitle() << ", and I like ponies!" << std::endl;
	return (os);
}


void Sorcerer::polymorph(Victim const &ref)
{
	ref.getPolymorphed();
}
