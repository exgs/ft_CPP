#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	Form("PresidentialPardonForm", 25, 5, false), target_("null")
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	Form("PresidentialPardonForm", 25, 5, false), target_(target)
{
	
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref) :
	Form(ref.getName(), ref.getSigngrade(), ref.getExecutegrade(), ref.getSign()), target_(ref.target_)
{
	
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresidentialPardonForm] " << "target : " << this->target_ << "소멸자를 호출함" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ref)
{
	if (this == &ref)
		return (*this);
	this->target_ = ref.target_;
	// bool		sign_;빼고는 모두 const
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	// 이미 예외처리 해줬음
	if (executor.getGrade() < this->getExecutegrade() && this->getSign() == true)
		std::cout << "Tells us " << this->target_ << "has been pardoned by Zafod Beeblebrox." << std::endl;
	else
		throw ExecuteFailException();
		// std::cout << "[PresidentialPardonForm] it's a failure." << std::endl;
}

const char* PresidentialPardonForm::ExecuteFailException::what() const _NOEXCEPT
{
	return ("Execute Fail Exception");
};
