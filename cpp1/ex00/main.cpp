#include "Pony.hpp"

int main()
{
    std::cout << "On Heap" << std::endl;
    ponyOnTheHeap();
	// pony 클래스가 함수 안에 동적할당으로 '초기화'되어있지만, 함수 마지막에 delete를 해주고 return도 없다.
    std::cout << std::endl;

    std::cout << "On Stack" << std::endl;
    ponyOnTheStack();
	// pony 클래스가 함수 안에 지역변수로 '초기화'되어있기때문에 함수 밖을 나오면, 접근 불가능하다.
    std::cout << std::endl;
	return (1);
}
// 따라서,  In both cases, the 'Pony' objects must not exist after the function hands off control. 이라고 본다.
