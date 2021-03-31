#include "Pig.hpp"
#include "Peon.hpp"
#include "Sorcerer.hpp"
#include "Victim.hpp"

int main()
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	std::cout << robert << jim << joe;
	robert.polymorph(jim);
	robert.polymorph(joe);
	// return 0;

	// 추가로해보고싶은건 상속관계에서 upcasting을 해보고싶음.
	// downcasting은 실행이되더라도 결점이 있는 코딩이기때문에 배제하도록하자!


	// Sorcerer icannotdo; // The class can't be instanciated without parameters
	// Peon a("Peon");
	// Victim b(a);
	// std::cout << a.getName() << std::endl;
	// std::cout << a.getTitle() << std::endl;
	// std::cout << a;
	// 스스로 getPolymorphed 할 수 있다는 점이 아쉽네
	//b.getPolymorphed();
	//b.getPolymorphed();
	// Pig pig("yunslee");
	// pig.getPolymorphed();
	// return (0);
}
