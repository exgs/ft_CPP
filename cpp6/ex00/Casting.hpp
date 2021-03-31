#ifndef CASTING_HPP
# define CASTING_HPP

#include <string>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <cmath>

// using namespace std;

enum datatype
{
	NONE = 0,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class Casting
{
	private:

	public:
		std::string	str_;
		char		char_bit1_;
		double		double_bit8_;
		float		float_bit4_;
		int			int_bit4_;
		bool		valid;
		
		datatype	type;
		bool		onlyrealnumber;
		Casting(char *str=NULL);
		Casting(const Casting& ref);
		virtual ~Casting();
		Casting& operator=(const Casting& ref);

		std::string	getstr() const;
		char		getCharbit1() const;
		double		getDoublebit8() const;
		float		getFloatbit4() const;
		int			getIntbit4() const;
		void		check_string();
		bool		is_exception(std::string str);
		bool		is_char(std::string str);
		bool		is_not_valid_num(std::string str);
		bool		is_int(std::string str);
		bool		is_float(std::string str);
		bool		is_double(std::string str);

		void		setBits();

		class NonDisplayableException : public std::exception
		{
		public:
			virtual const char* what() const throw();
		};

		class ImpossibleException : public std::exception
		{
		public:
			virtual const char* what() const throw();
		};

		class NotAcceptStringException : public std::exception
		{
		public:
			virtual const char* what() const throw();
		};


		void    toChar();
		void    toInt();
		void    toFloat();
		void    toDouble();
};

# endif
