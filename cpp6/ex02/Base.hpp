#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <sys/time.h>
#include <typeinfo>

// using namespace std;

class Base
{
	public:
		virtual ~Base(){};
};

class A : public Base
{
	public:
		A(){};
		virtual ~A(){};
		A(const A &ref){(A)ref;};
		A &operator=(const A &ref){(A)ref;return (*this);};
};

class B : public Base
{
	public:
		B(){};
		virtual ~B(){};
		B(const B &ref){(B)ref;};
		B &operator=(const B &ref){(B)ref;return (*this);};
};

class C : public Base
{
	public:
		C(){};
		virtual ~C(){};
		C(const C &ref){(C)ref;};
		C &operator=(const C &ref){(C)ref;return (*this);};
};

Base *generate(void);
void identify_from_pointer(Base *p);
void identify_from_reference(Base &p);

#endif
