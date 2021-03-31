#include <exception>
#include <iostream>

class Parent : public std::exception {
 public:
  virtual const char* what() const _NOEXCEPT{ return "Parent!\n"; }
};

class Child : public Parent {
 public:
  const char* what() const _NOEXCEPT override { return "Child!\n"; }
};

int func(int c)
{
	if (c == 1) {
		throw Parent();
	}
	else if (c == 2) {
		throw Child();
	}
	return 0;
}

int main()
{
	int c;
	std::cin >> c;

	try {
		func(c);
	}catch (Parent& p) { // Child()를 Parent &p 가 받을 수 있기 때문에 구분이 안된다. 순서를 뒤바꿔야한다!!
		std::cout << "Parent Catch!" << std::endl;
		std::cout << p.what();
	}catch (Child& c) {
		std::cout << "Child Catch!" << std::endl;
		std::cout << c.what();
	}
}
