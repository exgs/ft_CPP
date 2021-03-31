# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "Intern.hpp"

// BureaucratexectueForm(Form const & form) 를 실행시키면, form.execute(*this); 도 실행됨.
// 이중 throw

// Shrubbery : 145 137
// Robotomy : 72 45
// PresidentialPardonForm : 25 5
void try_all_form(Form &president, Form &robotomy, Form &shrubbery, Bureaucrat &b);

int main(void)
{
	Bureaucrat	b("b", 50);  // 50등급 아래(~150)로는 모두 싸인가능
	Bureaucrat	c("c", 2);  // 2등급 아래(~150)로는 모두 싸인가능

	Intern yunslee;

	//Form 부모 포인터로 받아야 자식포인터를 받을 수 있음. 대신 virtual이 아니라면 함수 사용에 제한이 있겟음
	Form *president = yunslee.makeForm("PresidentialPardonForm", "obama");
	Form *robotomy = yunslee.makeForm("RobotomyRequestForm", "jikang");
	Form *shrubbery = yunslee.makeForm("ShrubberyCreationForm", "BigBigTree");

	try_all_form(*president, *robotomy, *shrubbery, b);
	std::cout << "--------------- Form에다가 b의 싸인 시작! --------------" << std::endl;
	b.signForm(*president);
	b.signForm(*robotomy);
	b.signForm(*shrubbery);
	std::cout << "-----------------------------------------------------" << std::endl;
	try_all_form(*president, *robotomy, *shrubbery, b);
	std::cout << "--------------- Form에다가 c의 싸인 시작! --------------" << std::endl;
	c.signForm(*president);
	std::cout << "----------------------------------------------------" << std::endl;
	try_all_form(*president, *robotomy, *shrubbery, c);

	std::cout << "------------------------ end ------------------------" << std::endl;
	delete (PresidentialPardonForm *)president;
	delete (RobotomyRequestForm *)robotomy;
	delete (ShrubberyCreationForm *)shrubbery;
	return 0;
}

void try_all_form(Form &president, Form &robotomy, Form &shrubbery, Bureaucrat &b)
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
