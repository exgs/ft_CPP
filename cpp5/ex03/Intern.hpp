#ifndef INTERN_HPP
# define INTERN_HPP
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include <iostream>

class Intern
{
	private:

	public:
		Intern();
		~Intern();
		Intern(const Intern &ref);
		Intern &operator=(const Intern &ref);
		Form *makeForm(std::string, std::string);

};

Form *newPresidentialPardonForm(std::string target);
Form *newRobotomyRequestForm(std::string target);
Form *newShrubberyCreationForm(std::string target);

#endif
