#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "Form.hpp"

// using namespace std;
class Form;

class Bureaucrat
{
	private:
		const std::string	name_;
		int		grade_;
	public:
		Bureaucrat(const std::string name = "null", int grade = 75);
		Bureaucrat(const Bureaucrat& ref);
		Bureaucrat& operator=(const Bureaucrat& ref);
		~Bureaucrat();
		std::string getName() const;
		int getGrade() const;
		void incGrade();
		void decGrade();

		// ex01 추가함수
		void signForm(Form &ref);
		// void beSigned(Form &ref) const;

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const _NOEXCEPT;
			// const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const _NOEXCEPT;
	};
};
std::ostream &operator<<(std::ostream &os, Bureaucrat const &ref);

#endif
