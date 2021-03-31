// Bureaucrat 객체를 cout으로 출력하기위해 <<연산자 오버로딩을 해줌

#include "Bureaucrat.hpp"

int     main(void)
{
	/* Step1. 생성자에서 에러처리 */ 
	Bureaucrat A("A", 1);
	std::cout<<A;

	try
	{
		Bureaucrat B("B", 0);
		std::cout<<B;
	}
	catch(const std::exception& e) // Base class이기 때문에 받을 수 있음.
	{
		std::cout << e.what() << '\n'; // what()함수가 virtual 함수이기 때문에, GradTooHighException에서 정의한 함수가 출력됨.
	}

	try
	{
		Bureaucrat C("C", 1233);
		std::cout<<C;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	Bureaucrat *D;
	try
	{
		D = new Bureaucrat("D", 2);
		std::cout<<*D;
	}
	catch(const std::exception& e) 
	{
		std::cout<<e.what()<<'\n';
	}
	std::cout << "---------end---------" << std::endl;

	delete D; // try{}안에 스택 객체인지 힙 객체인지에 따라 주의사항이 있네요.
	return (1);

	/* Step2. incGrade(), decGrade()에서 에러처리 */ 
	// Bureaucrat F("F", 1);
	// std::cout << F;
	// try
	// {
	// 	F.incGrade();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout<<e.what()<<'\n';
	// }

	// Bureaucrat *G = new Bureaucrat("G", 150);
	// try
	// {
	// 	G->decGrade();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout<<e.what()<<'\n';
	// }
	// std::cout << "---------end---------" << std::endl;
	// return (1);
}
