#include "Ice.hpp"

Ice::Ice() :
	AMateria("ice")
{
	;
}

Ice::Ice(Ice const &ref) :
	AMateria(ref.getType(), ref.getXP())
{
	;
}

Ice::~Ice()
{
	;
}

Ice &Ice::operator=(Ice const &ref)
{
	if (this == &ref)
		return (*this);
	this->setType(ref.getType());
	this->setXP(ref.getXP());
	return (*this);
}


AMateria* Ice::clone() const
{
	return ((AMateria *)new Ice);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt an " << target.getName() << std::endl;
	if (this->getXP() >= 4294967290)
	{
		this->setXP(4294967295);
		return ;
	}
	this->setXP(this->getXP() + 10);
}
