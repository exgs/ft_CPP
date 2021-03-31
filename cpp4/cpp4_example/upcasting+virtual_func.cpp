#include <iostream>
#include <string>
using namespace std;


class Circle // 기본 클래스
{
protected:
	int radius;

public:
	void setRadius(int r){radius = r;}
	void showRadius(){cout << "반지름" << radius << endl;}
	
	virtual double getArea(){return (0);};
};

class Pizza : public Circle // 파생 클래스
{
public:
	double getArea(){return radius * radius * 3.14;};
};

int main()
{
	Circle circle;
	circle.setRadius(5);
	circle.showRadius();

	Pizza Hampizza;
	Hampizza.setRadius(10);
	cout << "햄 피자면적:" << Hampizza.getArea() << endl;

	Circle* cBase = &Hampizza; // 업 캐스팅
	cBase->setRadius(100);
	cBase->showRadius();

	cout << "치즈 피자면적:" << cBase->getArea() << endl; //virtual 안해주면 에러
	return (1);
}
