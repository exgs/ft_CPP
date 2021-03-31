#include "Bureaucrat.hpp"
#include "Form.hpp"

int     main(void)
{
	//Bureaucrat에 대한 것은 앞에서 보여줬으니 해당 객체의 예외처리는 보여주지 않아도 된다고 생각함.
	Bureaucrat	b("b", 50);  // 50등급이 기준
	
	Form 		f1("f1", 60);  // sign impossible
	Form 		f2("f2", 40);  // sign possible


	std::cout << "--- f1은 sign이 됨 ---" << std::endl;
	try
	{
		b.signForm(f1);  // 60등급보다 높은 50등급이라 sign 가능
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "--- f2은 sign이 안됨 ---" << std::endl;
	try
	{
		b.signForm(f2);  // 40등급보다 낮은 50등급이라 no sign
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	std::cout << "------------ 생성자에서 비정상 처리 ------------" << std::endl;
	try
	{
		Form 		f3("f3", 0);  // GradeTooHighException 함수에서 throw
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	try
	{
		Form 		f4("f4", 151);  // GradeTooLowException 함수에서 throw
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	std::cout << "------------ end ------------" << std::endl;
	return 0;
}
