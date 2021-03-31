#include "Victim.hpp"
#include "Sorcerer.hpp"

Victim::Victim(std::string name):
	name_(name)
{
	std::cout << "Some random victim called " << name_ << " just appeared!" << std::endl;
}

Victim::Victim(const Victim &ref):
	name_(ref.name_)
{
	std::cout << "Some random victim called " << name_ << " just appeared!" << std::endl;
}

Victim::~Victim()
{
	std::cout << "Victim " << name_ << " just died for no apparent reason!" << std::endl;
}

Victim &Victim::operator=(const Victim &ref)
{
	if (this == &ref)
		return (*this);
	name_ = ref.name_;
	return (*this);
}

std::string Victim::getName() const{return (name_);}

std::ostream &operator<<(std::ostream &os, const Victim &ref)
{
	std::cout << "I'm " << ref.getName() << " and I like otters!" << std::endl;
	return (os);
}

void Victim::getPolymorphed() const
{
	std::cout << name_ << " has been turned into a cute little sheep!" << std::endl;
}
