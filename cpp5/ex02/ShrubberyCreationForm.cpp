#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	Form("ShrubberyCreationForm", 145, 137, false), target_("null")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	Form("ShrubberyCreationForm", 145, 137, false), target_(target)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) :
	Form(ref.getName(), ref.getSigngrade(), ref.getExecutegrade(), ref.getSign()), target_(ref.target_)
{
	
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm] " << "target : " << this->target_ << "소멸자를 호출함." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
{
	if (this == &ref)
		return (*this);
	this->target_ = ref.target_;
	// bool		sign_;빼고는 모두 const
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() < this->getExecutegrade() && this->getSign() == true)
	{
		std::ofstream file_write;
		std::string filename = (this->target_);
		filename.append("_shrubbery");
		file_write.open(filename);
		std::cout << "Write Ascii tree, file name : " << filename << std::endl;
		std::string tree =
	"                                              .       \n \
                                        .         ;        \n \
           .              .              ;%     ;;         \n \
             ,           ,                :;%  %;          \n \
              :         ;                   :;%;'     .,   \n \
     ,.        %;     %;            ;        %;'    ,;     \n \
       ;       ;%;  %%;        ,     %;    ;%;    ,%'      \n \
        %;       %;%;      ,  ;       %;  ;%;   ,%;'       \n \
         ;%;      %;        ;%;        % ;%;  ,%;'         \n \
          `%;.     ;%;     %;'         `;%%;.%;'           \n \
           `:;%.    ;%%. %@;        %; ;@%;%'              \n \
              `:%;.  :;bd%;          %;@%;'                \n \
                `@%:.  :;%.         ;@@%;'                 \n \
                  `@%.  `;@%.      ;@@%;                   \n \
                    `@%%. `@%%    ;@@%;                    \n \
                      ;@%. :@%%  %@@%;                     \n \
                        %@bd%%%bd%%:;                      \n \
                          #@%%%%%:;;                       \n \
                          %@@%%%::;                        \n \
                          %@@@%(o);  . '                   \n \
                          %@@@o%;:(.,'                     \n \
                      `.. %@@@o%::;                        \n \
                         `)@@@o%::;                        \n \
                          %@@(o)::;                        \n \
                         .%@@@@%::;                        \n \
                         ;%@@@@%::;.                       \n \
                        ;%@@@@%%:;;;.                      \n \
                    ...;%@@@@@%%:;;;;,..                   \n";
		file_write.write(tree.c_str(), tree.size());
		file_write.close();
	}
	else
		throw ExecuteFailException();
		// std::cout << "[ShrubberyCreationForm] it's a failure." << std::endl;
}

const char* ShrubberyCreationForm::ExecuteFailException::what() const _NOEXCEPT
{
	return ("Execute Fail Exception");
};
