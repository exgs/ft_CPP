#include "Form.hpp"

Form::Form(const std::string &name, int signgrade, int executegrade, bool sign) :
	name_(name), signgrade_(signgrade), executegrade_(executegrade), sign_(sign)
{
	if (this->signgrade_ <= 0 || this->executegrade_ <= 0)
		throw Form::GradeTooHighException();
	if (this->signgrade_ >= 151 || this->executegrade_ >= 151)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& ref) :
	name_(ref.getName()), signgrade_(ref.getSigngrade()), executegrade_(ref.getExecutegrade()), sign_(ref.getSign())
{
	if (this->signgrade_ <= 0 || this->executegrade_ <= 0)
		throw Form::GradeTooHighException();
	if (this->signgrade_ >= 151 || this->executegrade_ >= 151)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
	std::cout << "[Form] " << this->getName() << " : 소멸자가 호출함." << std::endl;
}

Form& Form::operator=(const Form& ref)
{
	if (this == &ref)
		return (*this);
	// this->name_ = ref.name_; // constant라서 불가능.
	// this->grade_ = ref.grade_; // constant라서 불가능.
	// this->sign_ = ref.sign_; 
	return (*this);
}

std::string Form::getName() const{return (this->name_);}

int Form::getSigngrade() const{return (this->signgrade_);}

int Form::getExecutegrade() const{return (this->executegrade_);}

bool Form::getSign() const{return (this->sign_);}

std::ostream &operator<<(std::ostream &os, Form const &ref)
{
	std::cout << ref.getName() << ", Form signgrade " << ref.getSigngrade() << ", Form executegrade " << ref.getExecutegrade() <<", Form sign " << ref.getSign() << std::endl;
	return (os);
}

// 예외처리 클래스
const char* Form::GradeTooHighException::what() const _NOEXCEPT
{
	return ("Grade Too 'High' Exception");
}

const char* Form::GradeTooLowException::what() const _NOEXCEPT
{
	return ("Grade Too 'Low' Exception");
}

void Form::beSigned(Bureaucrat *ref)
{
	if (ref->getGrade() < this->getSigngrade())
		this->sign_ = true;
	else
		throw Form::GradeTooLowException();
}
