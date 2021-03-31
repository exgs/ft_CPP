#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	return 0;

	/* 나의 main문 변형 버전 */
	// IMateriaSource *src = new MateriaSource();
	// // 일부러 learnMateria에서는 메모리 누수가 안 나도록 만들었음.
	// // 이미 '그 타입'이 존재하는 경우. 넣지 않도록 함.
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// // src->learnMateria(new Ice());
	// // src->learnMateria(new Cure());

	// ICharacter *me = new Character("me");


	// // unequip에서는 메모리 누수가 나야하는 상황.
	// // 서브젝트 "must NOT delete Materia!"
	// AMateria *tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// // 메모리누수 나지 않도록 처리함.
	// std::cout << me->getInventory_num() << std::endl;
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// std::cout << me->getInventory_num() << std::endl;
	// tmp = src->createMateria("cure");
	// me->equip(tmp);

	// // 메모리누수 나야함.
	// // me->unequip(1);
	// // me->unequip(1);


	// ICharacter *bob = new Character("bob");

	// me->use(0, *bob);
	// me->use(1, *bob);
	// delete bob;
	// delete me;
	// delete src;
	// return 0;
}
