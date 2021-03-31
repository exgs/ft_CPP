#include "Cure.hpp"

Cure::Cure() :
	AMateria("cure")
{
	;
}

Cure::Cure(Cure const &ref) :
	AMateria(ref.getType(), ref.getXP())
{
	;
}

Cure::~Cure()
{
	;
}

Cure &Cure::operator=(Cure const &ref)
{
	if (this == &ref)
		return (*this);
	this->setType(ref.getType());
	this->setXP(ref.getXP());
	return (*this);
}

AMateria* Cure::clone() const
{
	return ((AMateria *)new Cure);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	if (this->getXP() >= 4294967290)
	{
		this->setXP(4294967295);
		return ;
	}
	this->setXP(this->getXP() + 10);
}
