#include <iostream>
using namespace std;

class Base
{
public:
	Base(int n) : value(n)
	{
		std::cout << "Base(" << n << ")"<< std::endl; // 값을 넣은 생성자를 호출했지만 호출되지않음
	}
	Base() : value(101)
	{ 
		std::cout << "Base()"<< std::endl; // 디폴트 생성자가 호출됨.
	}
	~Base() { std::cout << "~Base()"<< std::endl; }

	int value;
};

class One : virtual public Base
{
public:
  One() : Base(2) // 서로 다른 값으로 Base를 초기화 시킬 가능성이 있음
  { 
    std::cout << "One()"<< std::endl; 
  }
 ~One() { std::cout << "~One()"<< std::endl; }
};

class Two : virtual public Base
{
public:
  Two() : Base(2 + 4) // 서로 다른 값으로 Base를 초기화 시킬 가능성이 있음
  { 
    std::cout << "Two()"<< std::endl; 
  }
 ~Two() { std::cout << "~Two()"<< std::endl; }
};

class Leaf : public One, public Two
{
public:
	Leaf() : One(), Two()
	{
		std::cout << "Leaf()"<< std::endl;
	}
	~Leaf() { std::cout << "~Leaf()"<< std::endl; }
};

int main()
{
	Leaf temp;
	cout << temp.One::value << endl;
	cout << temp.Two::value << endl;
	cout << temp.value << endl; // Error
	cout << "------END------" << endl;
	return (0);
}
