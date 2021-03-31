#include "Array.hpp"

template <typename T>
void print_all(T &data, int size)
{
	std::cout << " - - - - - - - - - - " << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << data[i] << std::endl;
	}
}


int main()
{
	Array<int> a(5);
	Array<char>b(5);
	Array<std::string>c(5);
	Array<double>d(5);
	
	std::cout << "------ int ------" << std::endl;
	try
	{
		std::cout << a[2] << std::endl;
		a[2] = 2;
		std::cout << a[2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	::print_all(a, 5);


	std::cout << "------ char ------" << std::endl;
	try
	{
		std::cout << b[2] << std::endl;
		b[2] = 'a';
		std::cout << b[2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	::print_all(b, 5);


	std::cout << "------ string ------" << std::endl;
	try
	{
		std::cout << c[2] << std::endl;
		c[2] = "sdfdsfsd";
		std::cout << c[2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	::print_all(c, 5);


	std::cout << "------ double ------" << std::endl;
	try
	{
		std::cout << d[2] << std::endl;
		d[2] = 3.142;
		std::cout << d[2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	::print_all(d, 5);

	std::cout << "------ 복사 생성자 ------" << std::endl;
	Array<int>aa = a;
	::print_all(aa, aa.size());
	Array<int>aaa;
	::print_all(aaa, aaa.size());
	aaa = aa;
	::print_all(aaa, aaa.size());
	return (0);
}
