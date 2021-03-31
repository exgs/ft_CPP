#include "Intern.hpp"

Intern::Intern()
{

}

Intern::~Intern()
{

}

Intern::Intern(const Intern &ref)
{

}

Intern &Intern::operator=(const Intern &ref)
{
	if (this == &ref)
		return (*this);
	return (*this);
}

Form *Intern::makeForm(std::string form, std::string target)
{
	size_t count = 3;
	std::string Form_list[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	Form *(*Form_constructors[3])(std::string) = {newPresidentialPardonForm, newRobotomyRequestForm, newShrubberyCreationForm};
	for (size_t i = 0; i < count; i++)
	{
		if (Form_list[i].compare(form) == 0)
		{
			std::cout << "Intern creates " << form << std::endl;
			return Form_constructors[i](target);
		}
	}
	std::cout << "Intern can't make form asked." << std::endl;
	return (NULL);
}

Form *newPresidentialPardonForm(std::string target){return new PresidentialPardonForm(target);}

Form *newRobotomyRequestForm(std::string target){return new RobotomyRequestForm(target);}

Form *newShrubberyCreationForm(std::string target){return new ShrubberyCreationForm(target);}
