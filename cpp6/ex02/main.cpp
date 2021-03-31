#include "Base.hpp"

int main()
{
	srand(time(NULL));
	Base *pointer;
	pointer = generate();
	Base &reference = *pointer;

	identify_from_pointer(pointer);
	std::cout << "typeid로 알아보는 실제 derived 객체 : " << typeid(*pointer).name() << std::endl;
	identify_from_reference(reference);

	/* #include <typeinfo> 쓰지말래 */
	// cout << typeid(*pointer).name() << std::endl; // 실제 값 알아내는법
	// cout << typeid(pointer).name() << std::endl;
	// cout << typeid(B).before(typeid(Base)) << std::endl;
	delete pointer;
	return 0;
}
