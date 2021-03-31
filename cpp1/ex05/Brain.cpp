#include "Brain.hpp"

Brain::Brain(int iq, int eq, int scale):
	_iq(iq), _eq(eq), _scale(scale)
{}

Brain::~Brain()
{
	std::cout << "Brain이 소멸됬습니다." << std::endl;
}

Brain::Brain(const Brain &subject):
	_iq(subject._iq),
	_eq(subject._eq),
	_scale(subject._scale)
{}

Brain& Brain::operator=(const Brain &subject)
{
	if (this == &subject)
		return (*this);
	this->_iq = subject._iq;
	this->_eq = subject._eq;
	this->_scale = subject._scale;
	return (*this);
}

void Brain::setiq(int iq){this->_iq = iq;}
void Brain::seteq(int eq){this->_eq = eq;}
void Brain::setscale(int scale){this->_scale = scale;}
int Brain::getiq() const{return this->_iq;}
int Brain::geteq() const{return this->_eq;}
int Brain::getscale() const{return this->_scale;}

std::string Brain::identify() const
{
	std::stringstream address;
    address << this; // 구글링해서 찾았어.
    return (address.str());
}

// int Brain::identify()
// {
// 	long int address = (long int)this;
	// return (address);
	// std::stringstream address;
    // address << this;
    // return (address.str());
// }
