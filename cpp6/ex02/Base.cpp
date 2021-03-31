#include "Base.hpp"

Base *generate(void)
{
	timeval time;
	int idx;
	gettimeofday(&time, NULL);
	idx = rand() % 3;
	idx = time.tv_usec % 3; // 0,1,2 중 하나
	if (idx == 0)
		return (new A);
	else if (idx == 1)
		return (new B);
	else if (idx == 2)
		return (new C);
	return (new C);
}

void identify_from_pointer(Base *p)
{
	A *a; B *b; C *c;
	if ((a = dynamic_cast<A *>(p)))
		std::cout << "A" << std::endl;
	else if ((b = dynamic_cast<B *>(p)))
		std::cout << "B" << std::endl;
	else if ((c = dynamic_cast<C *>(p)))
		std::cout << "C" << std::endl;
}

void identify_from_reference(Base &p)
{
	int sum = 7;
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
	}
	catch(const std::exception& e)
	{
		sum -= 1;
	}

	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
	}
	catch(const std::exception& e)
	{
		sum -= 2;
	}

	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
	}
	catch(const std::exception& e)
	{
		sum -= 4;
	}
	if (sum == 1)
		std::cout << "A" << std::endl;
	else if (sum == 2)
		std::cout << "B" << std::endl;
	else if (sum == 4)
		std::cout << "C" << std::endl;
}
