//human.cpp
#include "Human.hpp"

Human::Human()
{
	this->_brain = new Brain();
}

Human::~Human()
{
	delete this->_brain;
	// this->_brain = nullptr; nullptr은 c+11 이후에 생긴거래.(by slack)
	this->_brain = NULL;
	std::cout << "Human의 소멸됬습니다." << std::endl;
}

Brain &Human::getBrain(){return (*(this->_brain));}
std::string Human::identify(){return (this->getBrain().identify());}
