#include "Peon.hpp"

Peon::Peon(std::string name): Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon &Peon::operator=(const Peon &ref)
{
	if (this == &ref)
		return (*this);
	name_ = ref.name_;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Peon &ref)
{
	std::cout << "I'm " << ref.getName() << " and I like otters!" << std::endl;
	return (os);
}

void Peon::getPolymorphed() const
{
	std::cout << name_ << " has been turned into a pink pony!" << std::endl;
}
