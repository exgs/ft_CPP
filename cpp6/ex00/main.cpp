#include "Casting.hpp"
// using namespace std;

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	Casting a(argv[1]);
	a.check_string();
	a.setBits();
	try
	{
		a.toChar();
	}
	catch(const std::exception& e)
	{
		std::cout << "char: ";
		std::cout << e.what() << '\n';
	}
	try
	{
		a.toInt();
	}
	catch(const std::exception& e)
	{
		std::cout << "int :";
		std::cout << e.what() << '\n';
	}
	
	try
	{
		a.toFloat();
	}
	catch(const std::exception& e)
	{
		std::cout << "float :";
		std::cout << e.what() << '\n';
	}

	try
	{
		a.toDouble();
	}
	catch(const std::exception& e)
	{
		std::cout << "double :";
		std::cout << e.what() << '\n';
	}
	return (0);
}
