#include "Pig.hpp"

Pig::Pig(std::string name_) : Victim(name_)
{
	std::cout << "Pig is borned" << std::endl;
}

Pig::Pig(const Pig &ref) : Victim(ref.name_)
{
	*this = ref;
	std::cout << "Pig is borned" << std::endl;
}

Pig::~Pig()
{
	std::cout << "Pig is died" << std::endl;
}

Pig& Pig::operator=(const Pig & ref)
{
	if (this == &ref)
		return (*this);
	name_ = ref.name_;
	return (*this);
}

void	Pig::getPolymorphed() const
{
	std::cout << name_ << " has been turned into a sexy pig!" << std::endl;
}
