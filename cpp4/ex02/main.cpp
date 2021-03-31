#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"
#include "Squad.hpp"

int main()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	delete vlc;


	/* main 함수 만들기 Deepcopy와 Softcopy 위주로 */
	// std::cout<<"======== start ========\n";
	// Squad s1;
	// ISpaceMarine* bob = new TacticalMarine;
	// ISpaceMarine* jim = new AssaultTerminator;
	// // s1에 하나만 push함
	// s1.push(bob);
	// for (int i = 0; i < s1.getCount(); ++i)
	// 	std::cout << "s1 : " << s1.getUnit(i) << std::endl;

	// // 주의사항! s1.getUnit(1)->rangedAttack(); 세그폴트의 위험성이 있음.
	// // ISpaceMarine* human;
	// // if ((human = s1.getUnit(0)) != NULL)
	// // {
	// // 	human->rangedAttack();
	// // }
	// // if ((human = s1.getUnit(1)) != NULL)
	// // {
	// // 	human->rangedAttack();
	// // }
	// Squad s2(s1);
	// s2.push(jim); // 주의사항: 이미 넣은 사람을 또다른 squad에 넣으면 안됨! 주소값복사만 일어나기때문에.
	// for (int i = 0; i < s2.getCount(); ++i)
	// 	std::cout << "s2 : " << s2.getUnit(i) << std::endl;
		
	// // case1. 복사생성자
	// Squad s3(s2);
	// for (int i = 0; i < s3.getCount(); ++i)
	// 	std::cout << "s3 : " << s3.getUnit(i) << std::endl;

	// // case2. = 연산자
	// // Squad s3;
	// // s3 = s2;
	// // for (int i = 0; i < s3.getCount(); ++i)
	// // 	std::cout << "s3 : " << s3.getUnit(i) << std::endl;

	// // // while(1); 메모리 누수도 valgrind와 leaks 둘다 나오지 않음
	// std::cout<<"===== end ====\n";
	return 0;
}
