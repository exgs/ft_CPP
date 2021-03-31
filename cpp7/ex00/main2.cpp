#include "whatever.hpp"

int main()
{
	int a = 2; int aa =3;
	char b = '1'; char bb = '2';
	unsigned char c = '2' ; unsigned char cc = '3' ;
	unsigned int d = 12; unsigned int dd =13;
	float f = 1.2; float ff = 13.2;
	double g = 1.2; double gg = 13.2;

	std::cout << "------------ swap ------------" << std::endl;
	yunslee::swap(a, aa);
	std::cout << a << " : " << aa << std::endl;
	yunslee::swap(b, bb);
	std::cout << b << " : " << bb << std::endl;
	yunslee::swap(c, cc);
	std::cout << c << " : " << cc << std::endl;
	yunslee::swap(d, dd);
	std::cout << d << " : " << dd << std::endl;
	yunslee::swap(f, ff);
	std::cout << f << " : " << ff << std::endl;
	yunslee::swap(g, gg);
	std::cout << g << " : " << gg << std::endl;
	std::cout << "------------ max ------------" << std::endl;
	std::cout << a << " : " << aa << "| max : " << yunslee::max(a, aa) << std::endl;
	std::cout << b << " : " << bb << "| max : " << yunslee::max(b, bb) << std::endl;
	std::cout << c << " : " << cc << "| max : " << yunslee::max(c, cc) << std::endl;
	std::cout << d << " : " << dd << "| max : " << yunslee::max(d, dd) << std::endl;
	std::cout << f << " : " << ff << "| max : " << yunslee::max(f, ff) << std::endl;
	std::cout << g << " : " << gg << "| max : " << yunslee::max(g, gg) << std::endl;

	std::cout << "------------ min ------------" << std::endl;
	std::cout << a << " : " << aa << "| min : " << yunslee::min(a, aa) << std::endl;
	std::cout << b << " : " << bb << "| min : " << yunslee::min(b, bb) << std::endl;
	std::cout << c << " : " << cc << "| min : " << yunslee::min(c, cc) << std::endl;
	std::cout << d << " : " << dd << "| min : " << yunslee::min(d, dd) << std::endl;
	std::cout << f << " : " << ff << "| min : " << yunslee::min(f, ff) << std::endl;
	std::cout << g << " : " << gg << "| min : " << yunslee::min(g, gg) << std::endl;

	std::cout << "------------ 객체 생성하기 ------------" << std::endl;

	A one; one.a = 100; // 객체의 비교연산자가 오버로딩되어있다면 max, min 함수가 잘 동작한다.
	A two; two.a = 200;

	std::cout << one.a << " : " << two.a << std::endl;
	std::cout << "------------ swap ------------" << std::endl;
	yunslee::swap(one, two);
	std::cout << one.a << " : " << two.a << std::endl;
	std::cout << "------------ max ------------" << std::endl;
	std::cout << one.a << " : " << two.a << "| max : " << yunslee::max(one.a, two.a) << std::endl;

	std::cout << "------------ min ------------" << std::endl;
	std::cout << one.a << " : " << two.a << "| min : " << yunslee::min(one.a, two.a) << std::endl;

	std::cout << "------------ 객체 생성하기 2 (평가표)------------" << std::endl;
	Awesome three(300); // 객체의 비교연산자가 오버로딩되어있다면 max, min 함수가 잘 동작한다.
	Awesome four(400);

	yunslee::swap(three, four);
	std::cout << three.getN() << " : " << four.getN() << std::endl;
	std::cout << "------------ max ------------" << std::endl;
	std::cout << three.getN() << " : " << four.getN() << "| max : " << yunslee::max(three, four).getN() << std::endl;

	std::cout << "------------ min ------------" << std::endl;
	std::cout << three.getN() << " : " << four.getN() << "| min : " << yunslee::min(three, four).getN() << std::endl;

	return (1);
}
