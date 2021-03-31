#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
// using namespace std;

class Bureaucrat;

class Form // 생성자 내부에 throw 넣음!!!!
{
	private :
		const std::string name_;
		const int signgrade_;
		const int executegrade_;
		bool sign_;
	
	public :
		Form(const std::string &name = "null", int signgrade = 75, int executegrade = 75, bool sign_ = false);
		Form(const Form& ref);
		Form& operator=(const Form& ref);
		~Form();
		std::string getName() const;
		int getSigngrade() const;
		int getExecutegrade() const;

		// Sign 관련 추가 함수
		bool getSign() const;
		void beSigned(Bureaucrat *ref);
		virtual void execute(Bureaucrat const & executor) const = 0;

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

std::ostream &operator<<(std::ostream &os, Form const &ref);

#endif
