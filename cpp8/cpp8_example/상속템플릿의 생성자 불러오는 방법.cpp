#include <iostream>
#include <string>

template <typename T>
class Base
{
	public :
		Base(){
			std::cout << __FUNCTION__ << std::endl;
		};
		virtual ~Base(){
			std::cout << __FUNCTION__ << std::endl;
		};
	
		void set(const T& aA);
		virtual void printContents(void) = 0;
	protected :
		T mA;
};

template <typename T>
void Base<T>::set(const T& aA)
{
    mA = aA;
    std::cout << __FUNCTION__ << std::endl;
}

 
template <typename T>
class A : public Base<T>
{
 
public :
	// A() : Base<T>(){
    A() : A:: template Base<T>(){
        std::cout << __FUNCTION__ << std::endl;
    };
    ~A(){
        std::cout << __FUNCTION__ << std::endl;
    }; 
    const T& get(void);
    virtual void printContents(void);
};
 
template <typename T>
const T& A<T>::get(void)
{
    std::cout << __FUNCTION__ << std::endl;
    return Base<T>::mA;
}
 
template <typename T>
void A<T>::printContents(void)
{
    std::cout << Base<T>::mA << std::endl;
}

struct person
{
    char name[128];
    int age;
};
 
class B : public Base<person>
{
 
public :
    B() : Base<person>(){
        std::cout << __FUNCTION__ << std::endl;
    };
    ~B(){
        std::cout << __FUNCTION__ << std::endl;
    }; 
    const person& get(void);
    virtual void printContents(void);
};
 
const person& B::get(void)
{
    std::cout << __FUNCTION__ << std::endl;
    return Base<person>::mA;
}
 
void B::printContents(void)
{
    std::cout << mA.name << " ";
    std::cout << mA.age << " " << std::endl;
}

int main(int argc, char* argv[])
{
    std::string str = "heesoon.kim";
    A<std::string> *pA = new A<std::string>();
    pA->set(str);
    pA->printContents();
    delete pA;
 
    person p ={"heesoon.kim", 41};
    B *pB = new B();
    pB->set(p);
    pB->printContents();
    delete pB;

	A<int> a;
 
    return 0;
}


