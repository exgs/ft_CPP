#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"

class AMateria;

class ICharacter
{
public:
	virtual ~ICharacter() {} // ICharacter로 가리키고 있어도 delete하면 자식 소멸자 먼저 호출되도록!
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;

	// 추가해준 함수, 서브젝트에서 주어진 메인문에서는 필요없지만,
	// 내가 작성한 main문에서 보여주고싶은 부분이 있어서 추가함.
	virtual int getInventory_num() const = 0;
};

#endif
