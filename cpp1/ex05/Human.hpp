#ifndef HUMAN_HPP
# define HUMAN_HPP
#include "Brain.hpp"

class Human
{
	private :
		// Brain _brain;
		const Brain _brain; // 서브젝트에서 요구하는 내용(that has a constant Brain attribute)
	public :
		Human();
		~Human();
		// Human(Human&); //뇌를 복제할 순 없잖아.(할당되었기 떄문에 '=' 쓰기도 어려움)
		// Human &operator=(Human &); //뇌를 복제할 순 없잖아.(할당되었기 떄문에 '=' 쓰기도 어려움)
		const Brain &getBrain();
		std::string identify();
};
#endif
