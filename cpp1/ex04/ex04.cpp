#include <iostream>
#include <string>
#include <iomanip>

int main()
{
	std::string *p1 = new std::string;
	*p1 = "HI THIS IS BRAIN";
	
	std::string word = "HI THIS IS BRAIN";
	//word.insert(2, "d"); c 언어랑 다른 점 Rvalue가 아님.
	std::string &p2 = word;
	
	std::cout << *p1 << std::endl;
	std::cout << p2 << std::endl;
	
	delete p1;
	/* 주소 값 출력해볼까? */
	std::cout << "==============번외===============" << std::endl;
	std::cout << std::setw(5) << "p1" 		<< " : " << p1 << std::endl;
	std::cout << std::setw(5) << "word"	 	<< " : " << &word << std::endl; // 두개가 같은게 신기해
	std::cout << std::setw(5) << "p2" 		<< " : " << &p2 << std::endl; // 이 두개가 같은게 신기해
	return (1);
}
