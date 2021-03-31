#include "Human.hpp"

Human::Human(): _brain(100,300,200){std::cout << "Human의 생성됬습니다." << std::endl;}
// 상수(const) 멤버를 초기화시키는 방법

/* 이 방법으로는 상수 멤버를 초기화 시킬 수 없음 */
// 객체의 생성 순서에서도 위에 있는 것이 먼저 실행된다고 본 것 같음.
// Human::Human()
// {
// 	_brain(100, 300, 200);
// 	std::cout << "Human의 생성됬습니다." << std::endl;
// }

Human::~Human()
{
	std::cout << "Human의 소멸됬습니다." << std::endl;
}

// 서브젝트에서 "constant Brain attribute"를 요구함. 형을 맞춰주기위해 const
const Brain &Human::getBrain()
{
	return (this->_brain);
}
std::string Human::identify()
{
	return (this->getBrain().identify());
}
