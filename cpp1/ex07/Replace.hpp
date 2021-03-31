#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <sys/stat.h>
# include <fstream>
# include <sstream>
# include <string>

enum error_num
{
	SUCCESS = 0,
	ERROR = 1,
	ERROR_ARGC = 2,
	ERROR_EMPTY_STRING = 3,
	ERROR_FILE_DOES_NOT_EXIST = 4
};

#define TRUE 1
#define FALSE 0

int	error(int error_num);
std::string ReplaceAll(std::string &str, const std::string& from, const std::string& to);

#endif
