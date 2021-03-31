#include "ZombieHorde.hpp"
// using namespace std;

int main()
{
	ZombieHorde horde1;
	horde1.announce();
	
	ZombieHorde horde2(30);
	horde2.announce();
	
	ZombieHorde horde3(-42);
	horde3.announce();

	// int형으로 생성자를 만들었기 때문에, -Wall -Wextra -Werror에 걸림
	// ZombieHorde horde4(202000000202202020);
	// horde4.announce();

	// 내가 생성자를 만들어주지 않아서 매칭이 되지않음 -> 컴파일 단계에서 에러가 뜸
	// ZombieHorde horde4(3, 2);
	// horde4.announce();
	return (1);
}
