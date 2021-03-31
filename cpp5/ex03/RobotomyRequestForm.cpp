#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	Form("RobotomyRequestForm", 72, 45, false), target_("null")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	Form("RobotomyRequestForm", 72, 45, false), target_(target)
{
	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref) :
	Form(ref.getName(), ref.getSigngrade(), ref.getExecutegrade(), ref.getSign()), target_(ref.target_)
{
	
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyRequestForm] " << "target : " << this->target_ << "소멸자를 호출함." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
{
	if (this == &ref)
		return (*this);
	this->target_ = ref.target_;
	// bool		sign_;빼고는 모두 const
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() < this->getExecutegrade() && this->getSign() == true)
		std::cout << this->target_ << " has been robotomized successfully 50% of the time." << std::endl;
	else
		throw ExecuteFailException();
		// std::cout << "[RobotomyRequestForm] it's a failure." << std::endl;
}

const char* RobotomyRequestForm::ExecuteFailException::what() const _NOEXCEPT
{
	return ("Execute Fail Exception");
};
