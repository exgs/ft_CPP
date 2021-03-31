#include "Casting.hpp"

Casting::Casting(char *str) :
	str_(str), valid(true), type(NONE), onlyrealnumber(false)
{

}

Casting::Casting(const Casting& ref) :
	str_(ref.str_), valid(true), type(NONE), onlyrealnumber(false)
{

}

Casting::~Casting()
{

}

Casting& Casting::operator=(const Casting& ref)
{
	if (this == &ref)
		return (*this);
	return (*this);
}

std::string	Casting::getstr() const{return (this->str_);}
char		Casting::getCharbit1() const{return (this->char_bit1_);}
double		Casting::getDoublebit8() const{return (this->double_bit8_);}
float		Casting::getFloatbit4() const{return (this->float_bit4_);}
int			Casting::getIntbit4() const{return (this->int_bit4_);}

void Casting::setBits()
{
	if (this->type == CHAR)
	{
		std::cout<< "[type]char" << std::endl;

		this->char_bit1_ = this->str_.c_str()[0];
		this->int_bit4_ = static_cast<int>(char_bit1_);
		this->float_bit4_ = static_cast<float>(char_bit1_);
		this->double_bit8_ = static_cast<double>(char_bit1_);
	}
	else if (this->type == INT)
	{
		std::cout<< "[type]int" << std::endl;
		this->int_bit4_ = atoi(this->str_.c_str());
		this->char_bit1_ = static_cast<char>(int_bit4_);
		this->float_bit4_ = static_cast<float>(int_bit4_);
		this->double_bit8_ = static_cast<double>(int_bit4_);
	}
	else if (this->type == FLOAT)
	{
		std::cout<< "[type]float" << std::endl;
		this->float_bit4_ = atof(this->str_.c_str());
		this->int_bit4_ = static_cast<int>(float_bit4_);
		this->char_bit1_ = static_cast<char>(float_bit4_);
		this->double_bit8_ = static_cast<double>(float_bit4_);
	}
	else if (this->type == DOUBLE)
	{
		std::cout<< "[type]double" << std::endl;
		this->double_bit8_ = atof(this->str_.c_str());
		this->int_bit4_ = static_cast<int>(double_bit8_);
		this->float_bit4_ = static_cast<float>(double_bit8_);
		this->char_bit1_ = static_cast<char>(double_bit8_);
	}
}

void	Casting::toChar()
{
	if (this->onlyrealnumber == true)
		throw ImpossibleException();
	if (this->valid == false)
		throw ImpossibleException();
	if ((this->getCharbit1() <= 127 && this->getCharbit1() > 31) != 1)
		throw NonDisplayableException();
	std::cout << "char: '" << this->getCharbit1() << "'" << std::endl;;
}

void	Casting::toInt()
{
	if (this->onlyrealnumber == true)
		throw ImpossibleException();
	if (this->valid == false)
		throw ImpossibleException();
	std::cout << "int: " << this->getIntbit4() << std::endl;;
}

void	Casting::toFloat()
{
	if (this->valid == false)
		throw ImpossibleException();
	if (this->getFloatbit4() != (double)this->getIntbit4() || this->onlyrealnumber == true)
		std::cout << "float: " << this->getFloatbit4() << "f"<< std::endl;
	else
		std::cout << "float: " << this->getFloatbit4() << ".0f" << std::endl;
}

void	Casting::toDouble()
{
	if (this->valid == false)
		throw ImpossibleException();
	if (this->getDoublebit8() != (double)this->getIntbit4() || this->onlyrealnumber == true)
		std::cout << "double: " << this->getDoublebit8() << std::endl;
	else
		std::cout << "double: " << this->getDoublebit8() << ".0" << std::endl;
}

const char* Casting::ImpossibleException::what() const throw()
{
	return ("Impossible");
}

const char* Casting::NonDisplayableException::what() const throw()
{
	return ("Non displayable");
}

const char* Casting::NotAcceptStringException::what() const throw()
{
	return ("Not Accept String");
}

bool	Casting::is_exception(std::string str)
{
	int i = 0;
	int count = 4;
	std::string float_exceptins[4] = {"nanf", "inff", "+inff", "-inff"};
	while (i < count)
	{
		if (str.compare(float_exceptins[i]) == 0)
		{
			this->valid = true;
			this->type = FLOAT;
			this->onlyrealnumber = true;
			return (true);
		}
		i++;
	}
	i = 0;
	std::string double_exceptins[4] = {"nan", "inf", "+inf", "-inf"};
	while (i < count)
	{
		if (str.compare(double_exceptins[i]) == 0)
		{
			this->valid = true;
			this->type = DOUBLE;
			this->onlyrealnumber = true;
			return (true);
		}
		i++;
	}
	return (false); // 해당영역이 아님
}

bool	Casting::is_char(std::string str)
{
	int count = 0;
	for (int i = 0; i < (int)str.size(); i++)
	{
		if (str[i] != '-' && str[i] != '+' && str[i] != '.' && !('0' <= str[i] && str[i] <= '9'))
		{
			if (i == (int)str.size() - 1 && str[i] == 'f' && str.size() != 1)
				break;
			count++;
			if ((int)str.size() != 1)
			{
				this->type = CHAR;
				this->valid = false;
				return (true);
			}
			else
			{
				this->type = CHAR;
				this->valid = true;
				return (true);
			}
		}
	}
	return (false);
}

bool	Casting::is_not_valid_num(std::string str)
{
	int dot_count = 0;
	std::string::iterator i = str.begin();
	if (*i == '.' )
		dot_count++;
	i++;
	while (i != str.end())
	{
		if (*i == '-' || *i == '+') //어짜피 atoi, atof에서 invalid로 보기떄문에
		{
			this->valid = false;
			this->type = NONE;
			return (true);
		}
		if (*i == '.' )
			dot_count++;
		i++;
	}
	if (dot_count >= 2)
	{
		this->valid = false;
		this->type = NONE;
		return (true);
	}
	return (false);
}

bool	Casting::is_int(std::string str)
{
	for (std::string::iterator i = str.begin(); i != str.end(); i++)
	{
		if (*i == '.' )
			return (false);
	}
	this->type = INT;
	long long int value; value = atoll(str.c_str());
	std::cout << value << std::endl;
	if ((long long int)INT_MAX < value || (long long int)INT_MIN > value)
		this->valid = false;
	return (true);
}

bool	Casting::is_float(std::string str)
{
	int temp; temp = str.size() - 1; 
	if (str[temp] == 'f')
	{
		this->type = FLOAT;
		this->valid = true;
		return (true);
	}
	else
		return (false);
	this->type = FLOAT;
	double value; value = atof(str.c_str());
	if ((double)FLT_MAX < value || (double)FLT_MIN > value)
	{
		this->type = FLOAT;
		// this->valid = false; overflow나는 것을 impossible로 표현할 것인지. inff로 표현할 것인지
	}
	return (true);
}

bool	Casting::is_double(std::string str)
{
	this->type = DOUBLE;
	double value; value = atof(str.c_str());
	if (-std::numeric_limits<double>::infinity() >= value || 
			std::numeric_limits<double>::infinity() <= value)
	{
		this->type = DOUBLE;
		// this->valid = false; overflow나는 것을 impossible로 표현할 것인지. inff로 표현할 것인지
	}
	return (true);
}

void	Casting::check_string()
{
	std::string str = this->str_;
	if (is_exception(str) == true)
		return ;
	if (is_char(str) == true)
		return ;
	if (is_not_valid_num(str) == true)
		return ;
	if (is_int(str) == true)
		return ;
	if (is_float(str) == true)
		return ;
	if (is_double(str) == true)
		return ;
}
