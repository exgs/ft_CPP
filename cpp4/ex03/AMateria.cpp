#include "AMateria.hpp"

AMateria::AMateria(std::string const& type) :
	_type(type), _xp(0)
{
	;
}

AMateria::AMateria(std::string const &type, unsigned int const &xp) :
	_type(type), _xp(xp)
{
	;
}

AMateria::AMateria() :
	_type("null"), _xp(0)
{
	;
}

AMateria::AMateria(AMateria const &ref) :
	_type(ref._type), _xp(ref._xp)
{
	;
}

AMateria::~AMateria()
{
	;
}

AMateria &AMateria::operator=(AMateria const &ref)
{
	if (this == &ref)
		return (*this);


	return (*this);
}

std::string const & AMateria::getType() const{return (_type);}

unsigned int AMateria::getXP() const{return (_xp);}

void AMateria::setType(std::string const &ref){this->_type = ref;}

void AMateria::setXP(unsigned int const &ref){this->_xp = ref;}

void AMateria::use(ICharacter& target) //their name is ice
{
	// AMateria는 추상클래스여서 생성될 수 없고, 이 함수는 virtual이기때문에, 실제로 실행되는일은 없음.
	std::cout << "[AMateria::use] "<< target.getName() <<":\"Speak aloud your name and skill!\"" << std::endl;
	_type += 10;
}
