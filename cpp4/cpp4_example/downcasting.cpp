#include <iostream>
#include <string>

using namespace std;

class Circle  // 기본 클래스
{
public:
	int radius;
public:
	void setRadius(int r){radius = r;}
	void showRadius(){cout << "반지름" << radius << endl;}
};

class Pizza : public Circle // 부모 클래스
{
public:
	double		area;
	double	getArea(){return radius * radius*3.14;};
	void	setArea(double area){this->area = area;};
	double	getArea_member(){return this->area;};

};

int main()
{
	Circle circle;
	circle.setRadius(5);
	circle.showRadius();

	Pizza *cDer;
	cDer = (Pizza*)&circle; //다운 캐스팅
	// cDer = (Pizza*)cBase; //다운 캐스팅
	cDer->setRadius(2);
	cDer->showRadius();
	cout << "치즈 피자면적:" << cDer->getArea() << endl;
	cDer->setArea(cDer->getArea()); // double area는 생성된 객체 circle에 존재하지 않는 메모리인데?
	cout << "치즈 피자면적:" << cDer->getArea_member() << endl;
	cout << "Pizza area:" << cDer->area << endl;
}
