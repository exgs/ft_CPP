#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
# include <fstream>
# include <sstream>
# include <string>

class ShrubberyCreationForm : public Form
{
private:
	std::string target_;
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& ref);
	~ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);

	void    execute(Bureaucrat const & executor) const;
	class ExecuteFailException : public std::exception
	{
		public:
			const char* what() const _NOEXCEPT;
	};
};

#endif
