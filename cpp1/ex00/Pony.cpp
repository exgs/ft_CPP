#include "Pony.hpp"

// using namespace std;

void Pony::set_name(std::string name){this->_name = name;}
void Pony::set_height(int height){_height = height;}
void Pony::set_weight(int weight){this->_weight = weight;}

std::string Pony::get_name(){return (this->_name);}
int Pony::get_height(){return (_height);}
int Pony::get_weight(){return (this->_weight);}

Pony::Pony():
_name("no named"), _height(0), _weight(0)
{}

Pony::Pony(std::string name, int height, int weight)
{
	this->_name = name;
	this->_height = height;
	this->_weight = weight;
}

Pony::~Pony()
{
	std::cout << "소멿자 출력 둘다 됩니다." << std::endl;
}

void Pony::print_pony()
{
	std::cout << "이름은 " << _name << std::endl;
	std::cout << "키는 " << _height << std::endl;
	std::cout << "이름은 " << _weight << std::endl;
}

void    ponyOnTheHeap()
{
    Pony *pony_heap = new Pony("yunslee_heap", 180, 30);
    pony_heap->print_pony();
    std::cout << "ponyOnTheHeap end" << std::endl;
    delete pony_heap;
}

void    ponyOnTheStack() 
{
    Pony pony_stack("yunslee_stack", 1800, 300);
    pony_stack.print_pony();
    std::cout << "ponyOnTheStack end" << std::endl;
}
