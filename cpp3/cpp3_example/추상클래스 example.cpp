#include <iostream>

using namespace std;
class Animal
{
public:
	~Animal() {cout << "Animal : 소멸자" << endl;}  // 가상 함수(소멸자)의 선언
    virtual void Cry()=0; // 순수 가상 함수의 선언
};

class Dog : public Animal
{
public:
    virtual void Cry() { cout << "멍멍!!" << endl; }
	virtual ~Dog() { cout << "Dog : 소멸자" << endl; }
};
 
class Cat : public Animal
{
public:
    virtual void Cry() { cout << "야옹야옹!!" << endl; }
	virtual ~Cat() { cout << "Cat : 소멸자" << endl; }
};

int main(void)
{
	Dog *my_dog = new Dog;
	my_dog->Cry();
	Cat *my_cat = new Cat;
	my_cat->Cry();
	cout << "-=-=-=-=-=-=-=-=-=-=-=-" << endl;
	Animal *temp;
	temp = my_dog;
	temp->Cry();
	temp = my_cat;
	temp->Cry();
	delete my_dog;

	// virtual ~Animal()보고 싶어서!
	delete temp;
	return 0;
}
