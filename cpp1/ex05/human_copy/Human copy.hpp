//Human.hpp
#include "Brain.hpp"

class Human
{
	private :
		Brain *_brain;
	public :
		Human();
		~Human();
		// Human(Human&); //뇌를 복제할 순 없잖아.(할당되었기 떄문에 '=' 쓰기도 어려움)
		// Human &operator=(Human &); //뇌를 복제할 순 없잖아.(할당되었기 떄문에 '=' 쓰기도 어려움)
		Brain &getBrain();
		std::string identify();
};
