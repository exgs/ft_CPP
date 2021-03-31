#include "span.hpp"

template<typename IT>
void print_all(IT s, IT e)
{
	IT it;
	for (it=s; it!=e; it++)
	{
		std::cout << *it << std::endl;
	}
}

int main()
{
	srand(time(NULL));
	int array[30];
	int count = 30;
	for (int i = 0; i < count; i++)
	{
		array[i] = i * i;
	}
	
	std::list<int> a;
	for (int i = 0; i < count; i++)
	{
		a.push_back(array[i]);
	}
	
	std::cout << "Case1: i * i for i in [0 ~ 29] 넣어보기" << std::endl;
	span span1(200);
	for (int i = 0; i < count; i++)
		span1.addNumber(array[i]);
	print_all(span1.list_.begin(), span1.list_.end());
	std::cout << "longestspan : " << span1.longestSpan() << std::endl;
	std::cout << "shortestspan : " << span1.shortestSpan() << std::endl;

	std::cout << "Case2: 임의의 값 넣어보기" << std::endl;
	span span2(10);
	span2.addNumber(5);
    span2.addNumber(3);
    span2.addNumber(17);
    span2.addNumber(-8925);
    span2.addNumber(11);
	print_all(span2.list_.begin(), span2.list_.end());
	std::cout << "longestspan : " << span2.longestSpan() << std::endl;
	std::cout << "shortestspan : " << span2.shortestSpan() << std::endl;

	std::cout << "Case3: 에러처리" << std::endl;

	std::cout << "Case3 - 1: =operator" << std::endl;

	try
	{
		span small_span(1);
		span big_span(100);
		small_span = big_span;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	

	std::cout << "Case3 - 2: addNumber" << std::endl;
	try
	{
		span small_span(1);
		small_span.addNumber(23);
		small_span.addNumber(233);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	


	std::cout << "Case3 - 3: over flow" << std::endl; // 일어날 수가 없긴함.
	try
	{
		span span4(2);
		span4.addNumber(2147483647);
		span4.addNumber(-2147483648);
		// std::cout << span4.longestSpan() << std::endl;
		std::cout << span4.shortestSpan() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	std::cout << "Case3 - 4: no member stored" << std::endl;
	try
	{
		span span4(2);
		span4.addNumber(-2147483648);
		// std::cout << span4.longestSpan() << std::endl;
		std::cout << span4.shortestSpan() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	std::cout << "Case4 - 10000 numbers " << std::endl;
	span test(10002);
	count = 10000;
	for (int i = 0; i < count; i++)
	{
		test.addNumber(rand());
	}

	try
	{
		std::cout << test.longestSpan() << std::endl;
		std::cout << test.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (1);
}
