#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// BureaucratexectueForm(Form const & form) 를 실행시키면, form.execute(*this); 도 실행됨.
// 이중 throw

// Shrubbery : (sign)145 (execute)137
// Robotomy : 72 45
// PresidentialPardonForm : 25 5
void try_all_form(PresidentialPardonForm &president, RobotomyRequestForm &robotomy, ShrubberyCreationForm &shrubbery, Bureaucrat &b);

int main(void)
{
	Bureaucrat	b("b", 50);  // 50등급 아래(~150)로는 모두 싸인가능
	Bureaucrat	c("c", 2);  // 2등급 아래(~150)로는 모두 싸인가능

	PresidentialPardonForm president("obama");
	RobotomyRequestForm robotomy("yunslee");
	ShrubberyCreationForm shrubbery("Big Big Tree");

	try_all_form(president, robotomy, shrubbery, b);
	std::cout << "--------------- Form에다가 b의 싸인 시작! --------------" << std::endl;
	b.signForm(president); //sign 안됨
	b.signForm(robotomy); //sign됨
	b.signForm(shrubbery); //sign됨
	std::cout << "----------------------------------------------------" << std::endl;
	try_all_form(president, robotomy, shrubbery, b);
	std::cout << "--------------- Form에다가 c의 싸인 시작! --------------" << std::endl;
	c.signForm(president);
	std::cout << "----------------------------------------------------" << std::endl;
	try_all_form(president, robotomy, shrubbery, c);

	std::cout << "------------------------ end ------------------------" << std::endl;
	return 0;
}

void try_all_form(PresidentialPardonForm &president, RobotomyRequestForm &robotomy, ShrubberyCreationForm &shrubbery, Bureaucrat &b)
{
	try
	{
		b.executeForm(president);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	try
	{
		b.executeForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	try
	{
		b.executeForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}
