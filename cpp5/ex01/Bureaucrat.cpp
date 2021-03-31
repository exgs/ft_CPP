#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) :
	name_(name), grade_(grade) 
{
	if (this->getGrade() <= 0)
			throw (Bureaucrat::GradeTooHighException());
	else if (this->getGrade() >= 151)
			throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) :
	name_(ref.name_), grade_(ref.grade_)
{
	if (this->getGrade() <= 0)
			throw (Bureaucrat::GradeTooHighException());
	else if (this->getGrade() >= 151)
			throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::~Bureaucrat()
{
	std::cout << this->getName() << " : 소멸자 호출." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref)
{
	if (this == &ref)
		return (*this);
	// name_  = ref.name_; const라서 불가능
	grade_ = ref.grade_;
	return (*this);
}

std::string Bureaucrat::getName() const{return (this->name_);}

int Bureaucrat::getGrade() const{return (this->grade_);}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &ref)
{
	std::cout << ref.getName() << ", bureaucrat grade " << ref.getGrade() << "." << std::endl;
	return (os);
}

void Bureaucrat::incGrade()
{
	if (this->getGrade() <= 0 + 1)
		throw (Bureaucrat::GradeTooHighException());
	this->grade_--;
}

void Bureaucrat::decGrade()
{
	if (this->getGrade() >= 151 - 1)
		throw (Bureaucrat::GradeTooLowException());
	this->grade_++;
}

// 예외처리 클래스
const char* Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
	return ("Grade Too 'High' Exception");
}

const char* Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
{
	return ("Grade Too 'Low' Exception");
}

void Bureaucrat::signForm(Form &ref)
{
	if (ref.getSign() == true)
		std::cout << this->name_ << " cannot sign " << ref.getName() << " because he see that is already signed." << std::endl;
	else
	{
		try
		{
			ref.beSigned(this);
			std::cout << this->name_ << " signs " << ref.getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
			std::cout << this->name_ << " cannot sign " << ref.getName() << " because of grade." << std::endl;
		}
		
	}
}
